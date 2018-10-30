//二分图匹配的问题···实际求的就是顶点个数减掉二分图匹配的最大值就好了···
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int V;
vector<int> G[550];
int match[550];
bool used[550];
void add_edge(int u,int v)
{
    G[u].push_back(v);
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
    for(int v=0;v<V;++v)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    while(scanf("%d",&V)!=EOF)
    {
        for(int i=0;i<=V;++i)
        {
            G[i].clear();
        }
        for(int j=0;j<V;++j)
        {
            int t,n;
            scanf("%d",&t);
            char tmp;
            cin>>tmp>>tmp>>n>>tmp;
            for(int i=0;i<n;++i)
            {
                int to;
                scanf("%d",&to);
                add_edge(t,to);
            }
        }
        int sub=bipartite_matching();
        printf("%d\n",V-sub);
    }
    return 0;
}