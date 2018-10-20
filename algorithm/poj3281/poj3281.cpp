//网络流问题···重点在于如何建图··别的没啥了···
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=1e9;
struct edge
{
    int to,cap,rev;
};
vector<edge> G[550];
bool used[550];
void add_edge(int from,int to,int cap)
{
    edge tmp;
    tmp.to=to;
    tmp.cap=cap;
    tmp.rev=G[to].size();
    G[from].push_back(tmp);
    tmp.to=from;
    tmp.cap=0;
    tmp.rev=G[from].size()-1;
    G[to].push_back(tmp);
}
int dfs(int v,int t,int f)
{
    if(v==t)
    {
        return f;
    }
    used[v]=true;
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
int N,F,D;
bool likeF[120][120];
bool likeD[120][120];
void solve()
{
    int s=N*2+F+D,t=s+1;
    for(int i=0;i<F;++i)
    {
        add_edge(s,N*2+i,1);
    }
    for(int i=0;i<D;++i)
    {
        add_edge(N*2+F+i,t,1);
    }
    for(int i=0;i<N;++i)
    {
        add_edge(i,N+i,1);
        for(int j=0;j<F;++j)
        {
            if(likeF[i][j])
            {
                add_edge(N*2+j,i,1);
            }
        }
        for(int j=0;j<D;++j)
        {
            if(likeD[i][j])
            {
                add_edge(N+i,N*2+F+j,1);
            }
        }
    }
    printf("%d\n",max_flow(s,t));
}
int main()
{
    scanf("%d%d%d",&N,&F,&D);
    for(int i=0;i<N;++i)
    {
        int f,d;
        scanf("%d%d",&f,&d);
        for(int j=0;j<f;++j)
        {
            int t;
            scanf("%d",&t);
            --t;
            likeF[i][t]=1;
        }
        for(int j=0;j<d;++j)
        {
            int t;
            scanf("%d",&t);
            --t;
            likeD[i][t]=1;
        }
    }
    solve();
    return 0;
}