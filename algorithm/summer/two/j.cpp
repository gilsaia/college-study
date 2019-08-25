#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll fac[100020],inv[100020];
ll pow_mod(ll a, int b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}
ll mul(ll a,ll b,ll mod){///二进制，按位相乘
    a=(a%mod+mod)%mod;
    b=(b%mod+mod)%mod;
    ll ans=0;
    while(b){
        if(b&1) ans+=a,ans=(ans>=mod?ans-mod:ans);
        b>>=1; a<<=1;
        a=(a>=mod?a-mod:a);
    }
    return ans;
}
void ext_gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (b == 0) {
        d = a, x = 1, y = 0;
    } else {
        ext_gcd(b, a%b, d, y, x);
        y -= x * (a / b);
    }
}
ll lucas(ll n,ll m,ll mod){
    ll ans=1;
    while(n&&m){
        ll a=n%mod,b=m%mod;
        if(a<b) return 0;
        ans=ans*fac[a]%mod*inv[b]%mod*inv[a-b]%mod;
        n/=mod,m/=mod;
    }
    return ans;
}

ll china(ll n,ll* a,ll* m){
    ll M=1,w,gcd,x,y,ans=0;
    for(int i=0;i<n;i++) M*=m[i];
    for(int i=0;i<n;i++){
        w=M/m[i];
        ext_gcd(m[i],w,gcd,x,y);
        ans=(ans+mul(mul(y,w,M),a[i],M)+M)%M;
    }
    return ans;
}
void init(ll n)
{
    fac[0]=1;
    for(int i=1;i<=n;++i)
    {
        fac[i]=fac[i-1]*i%n;
    }
    inv[n-1]=pow_mod(fac[n-1],n-2,n);
    for(int i=n-2;i>=0;--i)
    {
        inv[i]=inv[i+1]*(i+1)%n;
    }
}
ll a[20],p[20];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        for(int i=0;i<k;++i)
        {
            scanf("%lld",&p[i]);
            init(p[i]);
            a[i]=lucas(n,m,p[i]);
        }
        printf("%lld\n",china(k,a,p));
    }
    return 0;
}