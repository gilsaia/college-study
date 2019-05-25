#include<cstdio>
#include<algorithm>
using namespace std;
int dp[120][1020];
int save[120][1020];
int INF=1e9;
int main()
{
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=k;++j)
        {
            scanf("%d",&save[i][j]);
        }
    }
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            if(dp[i-1][j]==INF)
            {
                continue;
            }
            for(int t=1;t<=k&&(j+t)<=m;++t)
            {
                dp[i][j+t]=min(dp[i][j+t],dp[i-1][j]+save[i][t]);
            }
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}