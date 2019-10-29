#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1020],missile[1020];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i)
        {
            scanf("%d",&missile[i]);
            for(int j=0;j<i;++j)
            {
                if(missile[i]>missile[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}