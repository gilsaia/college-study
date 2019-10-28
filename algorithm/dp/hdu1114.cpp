#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int dp[520][10020];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int e,f;
        scanf("%d%d",&e,&f);
        int maxw=f-e;
        int n;
        scanf("%d",&n);
        memset(dp,INF,sizeof(dp));
        for(int i=1;i<=n;++i)
        {
            dp[i][0]=0;
            int w,v;
            scanf("%d%d",&v,&w);
            for(int j=1;j<=maxw;++j)
            {
                if(j<w)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-w]+v);
                }
            }
        }
        if(dp[n][maxw]==INF)
        {
            printf("This is impossible.\n");
        }
        else
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[n][maxw]);
        }
    }
    return 0;
}