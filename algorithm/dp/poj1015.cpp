#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int dp[22][820],e[220],v[220],last[22][820];
int fix=400;
int main()
{
    int num=1;
    int n,m;
    while(~scanf("%d%d",&n,&m),n+m)
    {
        memset(dp,-1,sizeof(dp));
        memset(last,-1,sizeof(last));
        dp[0][fix]=0;
        for(int i=0;i<n;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            e[i]=x-y;
            v[i]=x+y;
            for(int j=m;j>0;--j)
            {
                for(int t=0;t<=800;++t)
                {
                    if(((t-e[i])>=0)&&((t-e[i])<=800)&&(dp[j-1][t-e[i]])!=-1)
                    {
                        dp[j][t]=max(dp[j][t],dp[j-1][t-e[i]]+v[i]);
                    }
                }
            }
        }
        for(int i=0;i<=fix;++i)
        {
            int ans=-1;
            if(dp[m][fix+i]!=-1)
            {

            }
        }
    }
}