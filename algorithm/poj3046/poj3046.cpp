//据说是基础dp题然而还是不会做·····看了题解寻求思路
//这里的思路是已经优化过的思路了dp[i][j]表示前i种最多选j个所能达到的最大值
//dp[i][j]可以分为两部分 包含第i种和不包含第i种的，不包含第i种直接为dp[i-1][j]
//包含第i种则可考虑dp[i][j-1]为一部分含有全部第i种和不是全部第i种的(有前提条件j-1需大于第i种个数)，而相对的dp[i-1][j-sum[i]-1]即为dp[i][j-1]中包含了全部第i种的，减去即可
#include<stdio.h>
int dp[2][100010];
const int MOD=1000000;
int sum[1005];
int main()
{
    int T,A,S,B;
    scanf("%d%d%d%d",&T,&A,&S,&B);
    for(int i=0;i<A;i++)
    {
        int temp;
        scanf("%d",&temp);
        sum[temp]++;
    }
    dp[0][0]=1;
    dp[1][0]=1;
    for(int i=1;i<=T;i++)
    {
        for(int j=1;j<=B;j++)
        {
            if(j-sum[i]-1>=0)
            {
                dp[i%2][j]=(dp[(i-1)%2][j]+dp[i%2][j-1]-dp[(i-1)%2][j-sum[i]-1]+MOD)%MOD;
            }
            else
            {
                dp[i%2][j]=(dp[(i-1)%2][j]+dp[i%2][j-1])%MOD;
            }
        }
    }
    int ans=0;
    for(int i=S;i<=B;i++)
    {
        ans+=dp[T%2][i];
        ans%=MOD;
    }
    printf("%d\n",ans);
    return 0;
}