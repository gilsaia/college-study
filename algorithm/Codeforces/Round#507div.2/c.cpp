//这题···是真没理解题意···
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
const long long INF=1e18;
struct bus
{
    long long time,pos;
};
bool cmp(bus a,bus b)
{
    return a.pos<b.pos;
}
bus in[200020];
int main()
{
    long long n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        cin>>in[i].time;
    }
    for(int i=0;i<n;i++)
    {
        cin>>in[i].pos;
    }
    sort(in,in+n,cmp);
    int cnt=0;
    long long maxtime=INF;
    while(cnt!=n)
    {
        long long l=in[cnt].pos;
        long long mintime=in[cnt].time,lasttime=maxtime;
        maxtime=in[cnt].time;
        int mov=cnt+1;
        while(mov<n&&in[mov].pos==l)
        {
            maxtime=max(maxtime,in[mov].time);
            mintime=min(mintime,in[mov].time);
            mov++;
        }
        for(int i=cnt;i<mov;i++)
        {
            in[i].time=maxtime++;
        }
        if(lasttime!=INF)
        {
            if(lasttime>mintime)
            {
                printf("No\n");
                return 0;
            }
        }
        cnt=mov;
    }
    printf("Yes\n");
    for(int i=0;i<n;i++)
    {
        cout<<in[i].time+t;
    }
    printf("\n");
    return 0;
}