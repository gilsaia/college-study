#include<iostream>
#include<algorithm>
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
ll in(ll t, ll p) 
{
    return t == 1 ? 1 : (p - p / t) * in(p % t, p) % p;
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
    int T;
    cin>>T;
    ll r6=in(6,MOD),r4=in(4,MOD);
    for(int i=0;i<T;++i)
    {
        ll n;
        cin>>n;
        n--;
        n%=MOD;
        ll tmp=(n+1)*(n+1)%MOD;
        ll tmp2=tmp;
        tmp=tmp*(2*n+1)%MOD;
        tmp=tmp*n%MOD;
        tmp=tmp*r6%MOD;
        if(tmp<0)
        {
            tmp+=MOD;
        }
        tmp2=tmp2*n%MOD;
        tmp2=tmp2*n%MOD;
        tmp2=tmp2*r4%MOD;
        tmp=(tmp-tmp2+MOD)%MOD;
        while(tmp<0)
        {
            tmp+=MOD;
        }
        cout<<tmp%MOD<<endl;
    }
    return 0;
}