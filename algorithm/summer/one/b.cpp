#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD=9999991;
const int MAXN=1010;
ll mod_pow(ll x,ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}
ll lagin[MAXN],val[MAXN];
int n,m;
void init()
{
    for(int i=0;i<=n;++i)
    {
        ll tmp=1;
        for(int j=0;j<=n;++j)
        {
            if(i==j)
            {
                continue;
            }
            tmp=(tmp*(i-j))%MOD;
        }
        tmp=mod_pow(tmp,MOD-2);
        lagin[i]=val[i]*tmp%MOD;
    }
}
ll cal(ll x)
{
    ll use[MAXN];
    for(int i=0;i<=n;++i)
    {
        use[i]=1;
    }
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            if(i==j)
            {
                continue;
            }
            use[j]=(use[j]*(x-i))%MOD;
        }
    }
    ll ans=0;
    for(int i=0;i<=n;++i)
    {
        use[i]=(use[i]*lagin[i])%MOD;
        ans=(ans+use[i])%MOD;
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        val[0]=0;
        for(int i=0;i<=n;++i)
        {
            ll tmp;
            scanf("%lld",&tmp);
            val[i]+=tmp;
            val[i+1]=val[i];
        }
        init();
        for(int i=0;i<m;++i)
        {
            ll l,r;
            scanf("%lld%lld",&l,&r);
            ll res;
            if(l!=0)
            {
                res=(cal(r)-cal(l-1))%MOD;
            }
            else
            {
                res=cal(r)%MOD;
            }
            res=(res+MOD)%MOD;
            printf("%lld\n",res);
        }
    }
    return 0;
}