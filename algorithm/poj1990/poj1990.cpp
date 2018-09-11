//emmmmmmmm忘了写了···树状数组的例题···把牛们按耳背值排完序算就好···就是会爆int要注意···
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int N,M=0;
ll bitnum[20010],bitsum[20010];
struct cow
{
    int x,v;
    bool operator<(const cow &a)
    {
        return this->v<a.v;
    }
};
cow cows[20010];
ll tosum(ll *a,int i)
{
    ll s=0;
    while(i>0)
    {
        s+=a[i];
        i-=i&-i;
    }
    return s;
}
void toadd(ll *a,int i,int x)
{
    while(i<=M)
    {
        a[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&N);
    M=N;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&cows[i].v,&cows[i].x);
        M=max(M,cows[i].x);
    }
    sort(cows,cows+N);
    ll ans=0,sum=0;
    for(int i=0;i<N;i++)
    {
        ll minnum=tosum(bitnum,cows[i].x);
        ll minsum=tosum(bitsum,cows[i].x);
        ll tosub=minsum;
        ans+=(minnum*cows[i].x-tosub)*cows[i].v;
        ll besub=sum-tosub;
        ans+=(besub-(i-minnum)*cows[i].x)*cows[i].v;
        toadd(bitnum,cows[i].x,1);
        toadd(bitsum,cows[i].x,cows[i].x);
        sum+=cows[i].x;
    }
    printf("%lld\n",ans);
    return 0;
}