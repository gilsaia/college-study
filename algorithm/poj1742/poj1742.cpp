//多重背包dp问题，一般按照两层循环考虑
#include<iostream>
#include<string.h>
using namespace std;
int dp[100010];
int wei[120],num[120];
int main()
{
    int N,M;
    while(cin>>N>>M)
    {
        if(N==0&&M==0)
        {
            break;
        }
        for(int i=0;i<N;i++)
        {
            cin>>wei[i];
        }
        for(int i=0;i<N;i++)
        {
            cin>>num[i];
        }
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        int ans=0;
        for(int i=0;i<N;i++)
        {
            for(int t=0;t<=M;t++)
            {
                if(dp[t]>=0)
                {
                    dp[t]=num[i];
                }
                else if(t<wei[i])
                {
                    dp[t]=-1;
                }
                else
                {
                    dp[t]=dp[t-wei[i]]-1;
                }
            }
        }
        for(int i=1;i<=M;i++)
        {
            if(dp[i]>=0)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}