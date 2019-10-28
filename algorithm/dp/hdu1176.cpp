#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[100020][15];
int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        memset(dp,0,sizeof(dp));
        int maxt=0;
        for(int i=0;i<n;++i)
        {
            int x,t;
            scanf("%d%d",&x,&t);
            dp[t][x+1]++;
            maxt=max(maxt,t);
        }
        for(int t=maxt-1;t>=0;--t)
        {
            for(int j=1;j<=11;++j)
            {
                dp[t][j]+=max(dp[t+1][j-1],max(dp[t+1][j],dp[t+1][j+1]));
            }
        }
        printf("%d\n",dp[0][6]);
    }
    return 0;
}