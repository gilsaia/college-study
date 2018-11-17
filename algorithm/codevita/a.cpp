#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct team
{
    int id,score;
    double part;
    int partproblem[30];
    team()
    {
        id=0,score=0;
        part=0;
        for(int i=0;i<30;++i)
        {
            partproblem[i]=0;
        }
    }
    bool operator<(team &rhs)
    {
        if(score==rhs.score)
        {
            return part>rhs.part;
        }
        return score>rhs.score;
    }
}counter[10020];
struct problem
{
    int score,cases;
    double part;
    problem()
    {
        score=0,cases=0;
        part=0;
    }
}lists[30];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<10020;++i)
    {
        counter[i].id=i;
    }
    for(int i=0;i<n;++i)
    {
        char id;
        cin>>id;
        scanf("%d%d",&lists[id-'A'].score,&lists[id-'A'].cases);
        lists[id-'A'].part=(double)lists[id-'A'].score/(double)lists[id-'A'].cases;
    }
    int users,submit,maxnum=0;
    scanf("%d%d",&users,&submit);
    for(int i=0;i<submit;++i)
    {
        int id;
        scanf("%d",&id);
        maxnum=max(id,maxnum);
        char quesnum;
        cin>>quesnum;
        string condition;
        cin>>condition;
        int acnum=0;
        int pronum=quesnum-'A';
        for(int j=0;j<lists[pronum].cases;++j)
        {
            cin>>condition;
            if(condition[0]=='A')
            {
                acnum++;
            }
        }
        if(acnum==lists[pronum].cases)
        {
            if(counter[id].partproblem[pronum]!=lists[pronum].cases)
            {
                counter[id].score+=lists[pronum].score;
                counter[id].partproblem[pronum]=lists[pronum].cases;
            }
        }
        else
        {
            if(acnum>counter[id].partproblem[pronum])
            {
                counter[id].partproblem[pronum]=acnum;
            }
        }
    }
    for(int i=0;i<=maxnum;++i)
    {
        for(int j=0;j<26;++j)
        {
            if(counter[i].partproblem[j]!=lists[j].cases)
            counter[i].part+=lists[j].part*counter[i].partproblem[j];
        }
    }
    sort(counter,counter+10010);
    int rank=1,num=0;
    while(!(counter[num].score==0&&counter[num].part==0))
    {
        printf("%d %d %d ",rank,counter[num].id,counter[num].score);
        cout<<fixed<<setprecision(2)<<counter[num].part<<endl;
        rank++,num++;
    }
    return 0;
}