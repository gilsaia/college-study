//思路应该是一样的···不知道自己写的哪个边界处理错了···找了半天找不到···
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<string>
#include<iostream>
#include<queue>
#include<algorithm>
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,m;
int main()
{
    int a[200001];
    map<ll,ll> mp[11];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        ll x=a[i];
        for(int j=1;j<=10;j++)
        {
            x*=10;
            x%=m;
            mp[j][x]++;
        }
    }
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        int t=a[i]%m;
        int len=log10(a[i])+1;
        sum+=mp[len][(m-t)%m];
        ll x=1;
        for(int j=1;j<=len;j++) x=(x*10)%m; 
        if(((a[i]*x)%m+a[i]%m)%m==0) sum--;
    }
    printf("%I64d",sum);
}

/*#include<cstdio>
#include<map>
#include<utility>
#include<cmath>
using namespace std;
long long dat[200012];
int main()
{
    long long n,k;
    scanf("%lld%lld",&n,&k);
    map<long long,long long> tofind[12];
    for(int i=0;i<n;++i)
    {
        long long toin;
        scanf("%lld",&dat[i]);
        toin=dat[i];
        for(int j=0;j<9;++j)
        {       
            toin*=10;
            if(tofind[1+j].find(toin%k)==tofind[1+j].end())
            {
                tofind[1+j][toin%k]=1;
            }
            else
            {
                tofind[1+j][toin%k]++;
            }
        }
    }
    long long ans=0;
    for(int i=0;i<n;++i)
    {
        long long tmp=dat[i];
        int num=0;
        while(tmp>0)
        {
            ++num;
            tmp/=10;
        }
        if(tofind[num].find((k-(dat[i]%k))%k)!=tofind[num].end())
        {  
            ans+=tofind[num][(k-(dat[i]%k))%k];
        }
        long long shi=dat[i];
        while(num--)
        {
            shi*=10;
        }
        if((dat[i]+shi)%k==0)
        {
            --ans;
        }
    }
    printf("%lld\n",ans);
    return 0;
}*/
