//拓展欧几里得的算法······
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll mod_pow(ll x,ll n,ll mod)
{
    ll res=1;
    while(n>0)
    {
        if(n&1)
        {
            res=res*x%mod;
        }
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
int main()
{
    ll A,B,C,k;
    while(scanf("%lld%lld%lld%lld",&A,&B,&C,&k),(A+B+C+k))
    {
        ll b=B-A;
        if(!b)
        {
            printf("0\n");
            continue;
        }
        ll n=(ll)1<<k;
        ll x,y;
        ll d=extgcd(C,n,x,y);
        if(b%d==0)
        {
            x=((x*b/d)%(n/d)+(n/d))%(n/d);
            printf("%lld\n",x);
        }
        else
        {
            printf("FOREVER\n");
        }
    }
    return 0;
}