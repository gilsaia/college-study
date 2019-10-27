#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int dp[182];
struct edge
{
    int to,weight;
};
vector<edge> G[182];
int x[182],y[182],z[182];
int dfs(int start)
{
    if(dp[start]!=-1)
    {
        return dp[start];
    }
    int ans=0;
    for(int i=0;i<G[start].size();++i)
    {
        ans=max(ans,G[start][i].weight+dfs(G[start][i].to));
    }
    dp[start]=ans;
    return ans;
}
int main()
{
    int n;
    int index=1;
    while(~scanf("%d",&n),n)
    {
        int num=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;++i)
        {
            int w,t,q;
            scanf("%d%d%d",&w,&t,&q);
            x[num]=w,y[num]=t,z[num++]=q;
            x[num]=w,y[num]=q,z[num++]=t;
            x[num]=t,y[num]=w,z[num++]=q;
            x[num]=t,y[num]=q,z[num++]=w;
            x[num]=q,y[num]=w,z[num++]=t;
            x[num]=q,y[num]=t,z[num++]=w;
        }
        G[num].clear();
        for(int i=0;i<num;++i)
        {
            G[i].clear();
            for(int j=0;j<num;++j)
            {
                if(x[i]>x[j]&&y[i]>y[j])
                {
                    edge tmp;
                    tmp.to=j,tmp.weight=z[j];
                    G[i].push_back(tmp);
                }
            }
            edge tmp;
            tmp.to=i,tmp.weight=z[i];
            G[num].push_back(tmp);
        }
        int ans=dfs(num);
        printf("Case %d: maximum height = %d\n",index,ans);
        ++index;
    }
    return 0;
}