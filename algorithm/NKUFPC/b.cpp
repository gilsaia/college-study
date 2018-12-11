#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
typedef long long ll;
int dayofmonth[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct tmi
{
    long long tm_sec;   // seconds after the minute - [0, 60] including leap second
    ll tm_min;   // minutes after the hour - [0, 59]
    ll tm_hour;  // hours since midnight - [0, 23]
    ll tm_mday;  // day of the month - [1, 31]
    ll tm_mon;   // months since January - [0, 11]
    ll tm_year;  // years since 1900
};
long long mktime(tmi tm)
{
    long long ans=0;
    ans+=tm.tm_year*31536000;
    long long nowyear=tm.tm_year;
    if(nowyear>=0)
    {
        tm.tm_mday+=(nowyear-1)/4;
        tm.tm_mday-=(nowyear-1)/100;
        tm.tm_mday+=(nowyear-1)/400;
    }
    else
    {
        tm.tm_mday+=(nowyear+1)/4;
        tm.tm_mday-=(nowyear+1)/100;
        tm.tm_mday+=(nowyear+1)/400;
    }
    bool isrun=0;
    if((nowyear%4==0&&nowyear%100!=0)||nowyear%400==0)
    {
        isrun=true;
    }
    if(isrun&&tm.tm_mon>1)
    {
        tm.tm_mday++;
    }
    for(;tm.tm_mon>0;--tm.tm_mon)
    {
        tm.tm_mday+=dayofmonth[tm.tm_mon];
    }
    ans+=tm.tm_mday*86400;
    ans+=tm.tm_hour*3600;
    ans+=tm.tm_min*60;
    ans+=tm.tm_sec;
    return ans;
}
long long readtime()
{
    tmi thistime;
    char tmp;
    long long yeartmp,monthtmp;
    cin>>yeartmp>>tmp>>monthtmp>>tmp>>thistime.tm_mday>>thistime.tm_hour>>tmp>>thistime.tm_min>>tmp>>thistime.tm_sec;
    monthtmp-=1;
    thistime.tm_year=yeartmp,thistime.tm_mon=monthtmp;
    return mktime(thistime);
}
tmi starttime;
long long start,conend;
string testcondition[10]={" ","OLE","MLE","PE","RE","TLE","CE","WA","AC","SE"};
struct problem
{
    long long solvetime;
    int condition;//1-ole 2-mle 3-pe 4-re 5-tle 6-ce 7-wa 8-ac 9-se
};
bool cmppro(problem &a,problem &b)
{
    if(a.solvetime==b.solvetime)
    {
        return a.condition<b.condition;
    }
    return a.solvetime<b.solvetime;
}
struct ACMer
{
    string name;
    vector<problem> problemlist[15];
    long long penalty;
    int isAK;
    int solvenum;
    ACMer():penalty(0),isAK(1),solvenum(0){}
};
bool cmpACMer(ACMer &a,ACMer &b)
{
    if(a.solvenum==b.solvenum)
    {
        if(a.penalty==b.penalty)
        {
            return a.name<b.name;
        }
        return a.penalty<b.penalty;
    }
    return a.solvenum>b.solvenum;
}
struct thequicksolve
{
    long long solvetime;
    int sumnum,solvenum;
    vector<string> namelist;
    thequicksolve():sumnum(0),solvenum(0),solvetime(0){}
}quicklist[15];
int main()
{
    int N,K;
    cin>>N>>K;
    char tmp;
    long long yeartmp,monthtmp;
    cin>>yeartmp>>tmp>>monthtmp>>tmp>>starttime.tm_mday>>starttime.tm_hour>>tmp>>starttime.tm_min>>tmp>>starttime.tm_sec;
    monthtmp-=1;
    starttime.tm_year=yeartmp,starttime.tm_mon=monthtmp;
    start=mktime(starttime);
    long long hourtmp,mintmp,sectmp;
    cin>>hourtmp>>tmp>>mintmp>>tmp>>sectmp;
    mintmp+=hourtmp*60;
    sectmp+=mintmp*60;
    conend=start+sectmp;
    map<string,ACMer> thelist;
    for(int i=0;i<N;++i)
    {
        long long schoolnum,nowproblemnum,conditionnum;
        cin>>schoolnum;
        string nowname,problemnum,nowcondition,language;
        cin>>nowname>>problemnum>>nowcondition;
        nowproblemnum=problemnum[0]-'A';
        for(int j=1;j<=9;++j)
        {
            if(nowcondition==testcondition[j])
            {
                conditionnum=j;
                break;
            }
        }
        long long ct,cl;
        double cm;
        cin>>ct>>cm>>cl>>language;
        long long nowtime=readtime();
        if(nowtime<start||nowtime>=conend||conditionnum==9)
        {
            continue;
        }
        problem toin;
        toin.solvetime=nowtime;
        toin.condition=conditionnum;
        thelist[nowname].problemlist[nowproblemnum].push_back(toin);
    }
    vector<ACMer> resultlist;
    for(auto i=thelist.begin();i!=thelist.end();++i)
    {
        ACMer nowrun=i->second;
        nowrun.name=i->first;
        for(int j=0;j<K;++j)
        {
            sort(nowrun.problemlist[j].begin(),nowrun.problemlist[j].end(),cmppro);
            bool isac=0;
            long long nowpenalty=0;
            for(int t=0;t<nowrun.problemlist[j].size();++t)
            {
                if(!isac)
                {
                    if(nowrun.problemlist[j][t].solvetime<start||nowrun.problemlist[j][t].solvetime>=conend||nowrun.problemlist[j][t].condition==9)
                    {
                        continue;
                    }
                    if(nowrun.problemlist[j][t].condition!=8)
                    {
                        nowpenalty+=1200;
                        quicklist[j].sumnum++;
                    }
                    else
                    {
                        isac=1;
                        nowrun.solvenum++;
                        nowpenalty+=nowrun.problemlist[j][t].solvetime-start;
                        quicklist[j].solvenum++;
                        quicklist[j].sumnum++;
                    }
                }
                else
                {
                    if(nowrun.problemlist[j][t].solvetime<start||nowrun.problemlist[j][t].solvetime>=conend||nowrun.problemlist[j][t].condition==9)
                    {
                        continue;
                    }
                    if(nowrun.problemlist[j][t].condition!=8)
                    {
                        quicklist[j].sumnum++;
                    }
                    else
                    {
                        quicklist[j].sumnum++;
                        quicklist[j].solvenum++;
                    }
                }
            }
            if(isac==0)
            {
                nowrun.isAK=0;
            }
            else
            {
                nowrun.penalty+=nowpenalty;
                if(quicklist[j].namelist.empty()||quicklist[j].solvetime>=nowpenalty)
                {
                    if(quicklist[j].solvetime>nowpenalty)
                    {
                        quicklist[j].namelist.clear();
                    }
                    quicklist[j].solvetime=nowpenalty;
                    quicklist[j].namelist.push_back(nowrun.name);
                }
            }
        }
        resultlist.push_back(nowrun);
    }
    sort(resultlist.begin(),resultlist.end(),cmpACMer);
    int num=1;
    vector<string> AKlist;
    for(int i=0;i<resultlist.size();++i)
    {
        if(resultlist[i].isAK==1)
        {
            AKlist.push_back(resultlist[i].name);
        }
        /*if(resultlist[i].solvenum==0)
        {
            break;
        }*/
        cout<<"rank #";
        if(i!=0&&resultlist[i-1].solvenum==resultlist[i].solvenum&&resultlist[i-1].penalty==resultlist[i].penalty)
        {
            cout<<num;   
        }
        else
        {
            cout<<i+1;
            num=i+1;
        }
        cout<<":"<<resultlist[i].name<<endl;
    }
    for(int i=0;i<K;++i)
    {
        cout<<(char)('A'+i)<<"("<<quicklist[i].solvenum<<"/"<<quicklist[i].sumnum<<"):"<<endl;
        sort(quicklist[i].namelist.begin(),quicklist[i].namelist.end());
        if(quicklist[i].namelist.empty())
        {
            cout<<"NULL"<<endl;
            continue;
        }
        for(int j=0;j<quicklist[i].namelist.size();++j)
        {
            cout<<quicklist[i].namelist[j]<<endl;
        }
    }
    cout<<AKlist.size()<<endl;
    sort(AKlist.begin(),AKlist.end());
    for(int i=0;i<AKlist.size();++i)
    {
        cout<<AKlist[i]<<endl;
    }
    return 0;
}