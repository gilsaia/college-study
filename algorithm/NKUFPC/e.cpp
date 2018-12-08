#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
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
struct tosort
{
    ll cmp;
    ll num;
}element[100020];
bool cmp(tosort a,tosort b)
{
    return a.cmp<b.cmp;
}
ll am[100020],bm[100020];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        cin>>bm[i];
        ll tmp=bm[i]*bm[i];
        element[i].cmp=tmp+bm[i];
        element[i].num=i;
    }
    sort(element,element+m,cmp);
    for(int i=0;i<m;++i)
    {
        am[i]=bm[element[i].num];
    }
    for(int i=0;i<m;++i)
    {
        ll tmp;
        if(am[i]!=1)
        {
            tmp=(mod_pow(am[i],n,MOD)-1+MOD)%MOD;
            tmp*=am[i];
            tmp%=MOD;
            ll rever=mod_inverse(am[i]-1,MOD);
            tmp=(tmp*rever)%MOD;
        }
        else
        {
            tmp=n;
        }
        am[i]=tmp;
    }
    ll b1=1,b2=n,ans=0;
    for(int i=0;i<m;++i)
    {
        ll bs=(b1+b2)*n/2;
        bs%=MOD;
        ans=(ans+am[i]*bs)%MOD;
        b1+=n;
        b2+=n;
    }
    cout<<ans<<endl;
    return 0;
}