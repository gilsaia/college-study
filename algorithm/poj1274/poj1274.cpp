//二分图匹配的模板题···没啥可多说的实在···
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int V;
vector<int> G[420];
int match[420];
bool used[420];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();++i)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<V;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                ++res;
            }
        }
    }
    return res;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        V=m+n;
        for(int i=0;i<=V;++i)
        {
            G[i].clear();
        }
        for(int i=0;i<n;++i)
        {
            int j;
            scanf("%d",&j);
            for(int t=0;t<j;++t)
            {
                int u;
                scanf("%d",&u);
                u=u+n-1;
                add_edge(u,i);
            }
        }
        printf("%d\n",bipartite_matching());
    }
    return 0;
}