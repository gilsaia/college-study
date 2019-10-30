#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char cry[1020],xjj[1020];
int dp[1020][1020];
int main()
{
    while(~scanf("%s%s",cry,xjj))
    {
        memset(dp,0,sizeof(dp));
        int n=0;
        while(cry[n]!='\0')
        {
            ++n;
        }
        int m=0;
        while(xjj[m]!='\0')
        {
            ++m;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(cry[i-1]==xjj[j-1])
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}