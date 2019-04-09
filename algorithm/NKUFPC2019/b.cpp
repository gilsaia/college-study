#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll dp[2][5];
int main()
{
    int n;
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<5;++j)
        {
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    dp[1][0]=1;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        for(int m=1;m<=3;++m)
        {
            dp[1][(i+m)%4]+=dp[0][i%4];
            dp[1][(i+m)%4]%=MOD;
        }
        dp[0][i%4]=0;
        dp[0][(i+1)%4]+=dp[1][i%4];
        dp[1][i%4]=0;
        dp[0][(i+1)%4]%=MOD;
    }
    ll ans=(dp[0][n%4]+dp[1][n%4])%MOD;
    printf("%lld\n",ans);
    return 0;
}