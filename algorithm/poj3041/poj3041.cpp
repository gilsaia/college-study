//二分图匹配问题···确实没啥可说的···
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int V;
vector<int> G[5500];
int match[5500];
bool used[5500];
bool toprint[550][550];
int posx[550],posy[550];
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
    int N,K;
    scanf("%d%d",&N,&K);
    V=N*2;
    for(int i=0;i<K;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x-1,N+y-1);
    }
    printf("%d\n",bipartite_matching());
    return 0;
}