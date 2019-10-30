#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1020],dat[1020];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;++i)
        {
            scanf("%d",&dat[i]);
        }
        dp[0]=1;
        int ans=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if((dp[j]!=-1)&&(dat[j]<dat[i]))
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}