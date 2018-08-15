//变种01背包问题，将智力看做重量，幽默看做价值求dp后再遍历找两者皆不为负且最大值即可
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[2000010],cnt[2000010];
int w[105],v[105],sum;
int main()
{
    int n;
    int anstem=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int wei,val;
        scanf("%d%d",&wei,&val);
        if(wei<=0&&val<=0)
        {
            i--;
            n--;
            continue;
        }
        if(wei>=0&&val>=0)
        {
            anstem=anstem+wei+val;
            i--;
            n--;
            continue;
        }
        w[i]=wei;
        v[i]=val;
        w[i]+=1000;
        sum+=w[i];
    }
    memset(dp,-10000000,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int t=sum;t>=w[i];t--)
        {
            if(dp[t-w[i]]+v[i]-(cnt[t-w[i]]+1)*1000>dp[t]-cnt[t]*1000)
            {
                dp[t]=dp[t-w[i]]+v[i];
                cnt[t]=cnt[t-w[i]]+1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=sum;i++)
    {
        if(dp[i]>=0&&(i-cnt[i]*1000)>=0)
        {
            ans=max(ans,dp[i]+i-cnt[i]*1000);
        }
    }
    ans+=anstem;
    printf("%d\n",ans);
    return 0;
}
