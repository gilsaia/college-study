//这二分的非常迷···基本全靠看题解···
//vscode居然还报错···不知道哪来的···
#include<stdio.h>
#include<cstdio>
#include<cstring>
#include<functional>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const long long INF=1LL<<35;
const int maxn=1e6+100;
char str[120];
long long x[maxn],y[maxn],z[maxn],cnt;
long long sum(long long mid)
{
    long long sum=0;
    for(int i=0;i<cnt;i++)
    {
        if(mid<x[i])
        {
            continue;
        }
        sum+=(min(mid,y[i])-x[i])/z[i]+1;
    }
    return sum;
}
void solve()
{
    long long l=1,r=INF,ans=-1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(sum(mid)&1)
        {
            r=mid-1;
            ans=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    if(ans==-1)
    {
        printf("no corruption\n");
        return;
    }
    printf("%lld %lld\n",ans,sum(ans)-sum(ans-1));
}
int main()
{
    cnt=0;
    while(gets(str)!=NULL)
    {
        if(strlen(str)==0)
        {
            if(cnt==0)
                continue;
            solve();
            cnt=0;
        }
        else
        {
            sscanf(str,"%lld%lld%lld",&x[cnt],&y[cnt],&z[cnt]);
            cnt++;
        }
    }
    if(cnt)
        solve();
    return 0;
}