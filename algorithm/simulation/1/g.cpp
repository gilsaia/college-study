#include<cstdio>
using namespace std;
typedef long long ll;
ll MOD=1e9+7;
ll mod_pow(ll a,ll b)
{
    ll p=1;
    while(b)
    {
        if(b&1)
        {
            p=(p*a)%MOD;
        }
        b>>=1;
        a=(a*a)%MOD;
    }
    return p;
}
int main()
{
    ll n;
    while(scanf("%lld",&n)!=EOF)
    {
        ll res=0;
        res+=mod_pow(2,n);
        res=res*((n-1)%MOD)%MOD;
        res=(res+1)%MOD;
        printf("%lld\n",res);
    }
    return 0;
}