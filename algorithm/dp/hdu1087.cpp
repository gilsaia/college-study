#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[1020];
ll tmp[1020];
int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        memset(dp,0,sizeof(dp));
        tmp[0]=0;
        ll ans=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&tmp[i]);
            for(int j=0;j<i;++j)
            {
                if(tmp[j]<tmp[i])
                {
                    dp[i]=max(dp[i],dp[j]+tmp[i]);
                }
            }
            ans=max(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}