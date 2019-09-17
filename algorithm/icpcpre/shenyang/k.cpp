#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll dat[120];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll k,n;
        scanf("%lld%lld",&k,&n);
        ll sum=0;
        for(int i=0;i<k;++i)
        {
            ll tmp;
            scanf("%d",&tmp);
            sum+=tmp;
            sum%=MOD;
        }
        ll tes=0;
        for(int i=0;i<k;++i)
        {
            ll tmp;
            scanf("%lld",&dat[i]);
            tes+=dat[i];
            tes%=MOD;
        }
        ll tim=(n-k)/k;
        tes%=MOD;
        tim%=MOD;
        sum+=(tes*tim);
        sum%=MOD;
        int m=n%k;
        for(int i=0;i<m;++i)
        {
            sum+=dat[i];
            sum%=MOD;
        }
        printf("%lld\n",sum);
    }
    return 0;
}