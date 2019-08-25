#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[10020];
const ll MOD=1e9+7;
int main()
{
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=10000;++i)
    {
        dp[i]=dp[i-2]*2+2;
        dp[i]=dp[i]%MOD;
    }
    int K;
    scanf("%d",&K);
    for(int i=0;i<K;++i)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}