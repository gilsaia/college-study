//基础dp题然而仍旧不太会做··还需努力
#include<stdio.h>
int dp[1020][32];
int str[1020];
int max(int a,int b)
{
   return (a>b)?a:b;
}
int main()
{
    int T,W;
    scanf("%d%d",&T,&W);
    for(int i=1;i<=T;i++)
    {
        int temp;
        scanf("%d",&temp);
        str[i]=temp;
    }
    for(int i=1;i<=T;i++)
    {
        for(int t=0;t<=W;t++)
        {
            if(t>0)
            {
                dp[i][t]=max(dp[i-1][t],dp[i-1][t-1]);
            }
            else
            {
                dp[i][t]=dp[i-1][t];
            }
            int temp=(t%2==0)?2-str[i]:str[i]-1;
            dp[i][t]+=temp;
        }
    }
    printf("%d\n",dp[T][W]);
    return 0;
}