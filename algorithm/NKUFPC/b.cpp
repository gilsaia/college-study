#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
time_t readtime()
{
    tm thistime;
    char tmp;
    int yeartmp,monthtmp;
    cin>>yeartmp>>tmp>>monthtmp>>tmp>>thistime.tm_mday>>thistime.tm_hour>>tmp>>thistime.tm_min>>tmp>>thistime.tm_sec;
    yeartmp-=1900,monthtmp-=1;
    thistime.tm_year=yeartmp,thistime.tm_mon=monthtmp;
    return mktime(&thistime);
}
tm starttime;
time_t start,conend;
string testcondition[10]={" ","OLE","MLE","PE","RE","TLE","CE","WA","AC","SE"};
struct problem
{
    time_t solvetime;
    int condition;//1-ole 2-mle 3-pe 4-re 5-tle 6-ce 7-wa 8-ac 9-se
};
bool cmppro(problem &a,problem &b)
{
    return a.solvetime<b.solvetime;
}
struct ACMer
{
    string name;
    vector<problem> problemlist[15];
    int penalty;
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
    time_t solvetime;
    int sumnum,solvenum;
    vector<string> namelist;
    thequicksolve():sumnum(0),solvenum(0),solvetime(0){}
}quicklist[15];
int main()
{
    int N,K;
    cin>>N>>K;
    char tmp;
    int yeartmp,monthtmp;
    cin>>yeartmp>>tmp>>monthtmp>>tmp>>starttime.tm_mday>>starttime.tm_hour>>tmp>>starttime.tm_min>>tmp>>starttime.tm_sec;
    yeartmp-=1900,monthtmp-=1;
    starttime.tm_year=yeartmp,starttime.tm_mon=monthtmp;
    start=mktime(&starttime);
    int hourtmp,mintmp,sectmp;
    cin>>hourtmp>>tmp>>mintmp>>tmp>>sectmp;
    mintmp+=hourtmp*60;
    sectmp+=mintmp*60;
    conend=start+sectmp;
    map<string,ACMer> thelist;
    for(int i=0;i<N;++i)
    {
        int schoolnum,nowproblemnum,conditionnum;
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
        int ct,cl;
        double cm;
        cin>>ct>>cm>>cl>>language;
        time_t nowtime=readtime();
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
            time_t nowpenalty=0;
            for(int t=0;t<nowrun.problemlist[j].size();++t)
            {
                if(!isac)
                {
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
        cout<<"rank #";
        if(i!=0&&resultlist[i-1].penalty==resultlist[i].penalty)
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