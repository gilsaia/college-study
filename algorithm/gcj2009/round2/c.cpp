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
const int MAX_N=100;
const int MAX_K=25;
int N,K,P[MAX_N][MAX_K];
void solve()
{
    V=N*2;
    for(int i=0;i<V;++i)
    {
        G[i].clear();
    }
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(i==j)
            {
                continue;
            }
            bool f=true;
            for(int k=0;k<K;++k)
            {
                if(P[j][k]>=P[i][k])
                {
                    f=false;
                }
            }
            if(f)
            {
                add_edge(i,N+j);
            }
        }
    }
    int ans=N-bipartite_matching();
    printf("%d\n",ans);
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        scanf("%d%d",&N,&K);
        for(int j=0;j<N;++j)
        {
            for(int k=0;k<K;++k)
            {
                scanf("%d",&P[j][k]);
            }
        }
        printf("Case #%d: ",i);
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}