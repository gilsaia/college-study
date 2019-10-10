#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1505; //这个值要超过两边个数的较大者，因为有link
int link[maxn];
bool used[maxn];
vector<int> G[maxn];
int uN;
bool dfs(int u)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        if (!used[G[u][i]])
        {
            used[G[u][i]] = true;
            if (link[G[u][i]] == -1 || dfs(link[G[u][i]]))
            {
                link[G[u][i]] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int u;
    int res = 0;
    memset(link, -1, sizeof(link));
    for (u = 0; u < uN; u++)
    {
        memset(used, false, sizeof(used));
        if (dfs(u))
            res++;
    }
    return res;
}
vector<int> edges[maxn];
int belong[maxn];
int bidfs(int v)
{
    int res=1;
    for(int i=0;i<edges[v].size();++i)
    {
        if(belong[edges[v][i]]==belong[v])
        {
            return 0;
        }
        else if(belong[edges[v][i]]==-1)
        {
            belong[edges[v][i]]=(belong[v]+1)%2;
            res=bidfs(edges[v][i]);
            if(res==0)
            {
                break;
            }
        }
    }
    return res;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;++i)
        {
            edges[i].clear();
        }
        for(int i=0;i<m;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            --u,--v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        memset(belong,-1,sizeof(belong));
        int can=1;
        for(int i=0;i<n;++i)
        {
            if(belong[i]==-1)
            {
                belong[i]=0;
                can=bidfs(i);
                if(can==0)
                {
                    break;
                }
            }
        }
        if(!can)
        {
            printf("No\n");
            continue;
        }
        uN=0;
        G[0].clear();
        for(int i=0;i<n;++i)
        {
            if(belong[i]==0)
            {
                for(int j=0;j<edges[i].size();++j)
                {
                    G[uN].push_back(edges[i][j]);
                }
                ++uN;
                G[uN].clear();
            }
        }
        int ans=hungary();
        printf("%d\n",ans);
    }
    return 0;
}