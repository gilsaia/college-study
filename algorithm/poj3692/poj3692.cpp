//二分图匹配的题···这个题要反向思考···把不认识的人连边这样最大独立集就是两两认识的人了···然后通过二分图匹配的方法求出最大匹配，用总顶点个数减最大匹配即为最大独立集（二分图才可使用）
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int V;
vector<int> G[550];
int match[550];
bool used[550];
bool toprint[550][550];
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
    int Gir,B,M;
    for(int k=1;;++k)
    {
        scanf("%d%d%d",&Gir,&B,&M);
        if(!(Gir&&B&&M))
        {
            break;
        }
        V=Gir+B;
        memset(toprint,true,sizeof(toprint));
        for(int i=0;i<=Gir+B;++i)
        {
            G[i].clear();
        }
        for(int i=0;i<M;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            toprint[a][b+Gir]=toprint[b+Gir][a]=false;
        }
        for(int i=1;i<=Gir;++i)
        {
            for(int j=1+Gir;j<=Gir+B;++j)
            {
                if(toprint[i][j])
                {
                    add_edge(i,j);
                    add_edge(j,i);
                }
            }
        }
        int sub=bipartite_matching();
        printf("Case %d: %d\n",k,V-sub);
    }
    return 0;
}