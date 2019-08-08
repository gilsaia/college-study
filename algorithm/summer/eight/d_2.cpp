#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll inv(ll a, ll p)
{
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}
int main()
{
    ll fir=inv(2,MOD),sec=inv(24,MOD);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        ll tmp;
        scanf("%lld",&tmp);
        tmp%=MOD;
        ll cod=1,ans=1;
        for(ll i=0;i<4;++i)
        {
            cod=cod*(tmp-i)%MOD;
            if(i==1)
            {
                ans=ans+(cod*fir);
                ans%=MOD;
            }
            if(i==3)
            {
                ans=ans+(cod*sec);
                ans%=MOD;
            }
        }
        printf("Case #%d: %lld\n",i,ans);
    }
    return 0;
}