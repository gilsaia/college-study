#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[210][210];
vector<int> towrite[210];
int n,m;
void dfs(int t)
{
    for(int i=0;i<towrite[t].size();++i)
    {
        int now=towrite[t][i];
        if(towrite[now].size()>0)
        {
            dfs(now);
        }
        for(int j=m;j>1;--j)
        {
            for(int k=1;k<j;++k)
            {
                dp[t][j]=max(dp[t][j],dp[t][k]+dp[now][j-k]);
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n&&m)
    {
        ++m;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;++i)
        {
            towrite[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            towrite[a].push_back(i);
            for(int j=0;j<=m;++j)
            {
                dp[i][j]=b;
            }
        }
        dfs(0);
        printf("%d\n",dp[0][m]);
    }
    return 0;
}