#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int flyod[120][120];
int vis[120],link[120];
int n;
int dfs(int u)
{
    for(int i=1;i<=n;++i)
    {
        if(flyod[u][i]&&!vis[i])
        {
            vis[i]=1;
            if(link[i]==0||dfs(link[i]))
            {
                link[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m;
        scanf("%d%d",&n,&m);
        memset(flyod,0,sizeof(flyod));
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            flyod[a][b]=1;
        }
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    flyod[i][j]|=(flyod[i][k]&flyod[k][j]);
                }
            }
        }
        int res=0;
        memset(link,0,sizeof(link));
        for(int i=1;i<=n;++i)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))
            {
                ++res;
            }
        }
        printf("%d\n",n-res);
    }
    return 0;
}