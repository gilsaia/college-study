#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll save[100020];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&save[i]);
    }
    ll ans=0,tmpsave=0,tmpadd=0;
    ans+=(save[n]*save[n])%MOD;
    tmpadd+=save[n];
    for(int i=n-1;i>0;--i)
    {
        tmpsave=tmpsave*2%MOD;
        tmpadd=(tmpadd+save[i])%MOD;
        ll tmpmul=(tmpsave+tmpadd)%MOD;
        ans=(ans+save[i]*tmpmul%MOD)%MOD;
        tmpadd=(tmpadd-save[i+1]+MOD)%MOD;
        tmpsave=(tmpsave+save[i+1])%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}