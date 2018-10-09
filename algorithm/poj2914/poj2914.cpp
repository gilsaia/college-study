#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=1e9;
struct edge
{
    int to,cap,rev;
};
vector<edge> G[520];
bool used[520];
void add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}
int dfs(int v,int t,int f)
{
    if(v==t)
    {
        return f;
    }
    used[v]=1;
    for(int i=0;i<G[v].size();++i)
    {
        edge &e=G[v][i];
        if(!used[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        memset(used,0,sizeof(used));
        int f=dfs(s,t,INF);
        if(f==0)
        {
            return flow;
        }
        flow+=f;
    }
}
int tocal[520];
int main()
{
    int N,M;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        memset(tocal,0,sizeof(tocal));
        for(int i=0;i<=N+3;++i)
        {
            G[i].clear();
        }
        for(int i=0;i<M;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            ++a,++b;
            tocal[a]+=c;
            tocal[b]+=c;
            add_edge(a,b,c);
            add_edge(b,a,c);
        }
        for(int i=1;i<=N;++i)
        {
            add_edge(0,i,tocal[i]);
            add_edge(i,N+2,tocal[i]);
        }
        int ans=max_flow(0,N+2);
        printf("%d\n",ans);
    }
    return 0;
}