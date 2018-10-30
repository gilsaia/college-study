//最大流的问题···实际问的是最大权闭合图，大概方法正的点和s连线···负的绝对值和t连线···然后点之间线容量要无限大···正的点权的和减最大流即为最大权···至于个数就是残余网络剩余的节点个数···
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll INF=1e13;
struct edge
{
    int to;
    ll cap,rev;
    edge(int t=0,ll ca=0,ll re=0):to(t),cap(ca),rev(re){}
};
vector<edge> G[5020];
int level[5020];
int iter[5020];
void add_edge(int from,int to,ll cap)
{
    edge temp(to,cap,G[to].size());
    G[from].push_back(temp);
    edge temp2(from,0,G[from].size()-1);
    G[to].push_back(temp2);
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        for(int i=0;i<G[v].size();++i)
        {
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
ll dfs(int v,int t,ll f)
{
    if(v==t)
    {
        return f;
    }
    for(int &i=iter[v];i<G[v].size();++i)
    {
        edge &e=G[v][i];
        if(e.cap>0&&level[v]<level[e.to])
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
ll max_flow(int s,int t)
{
    ll flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0)
        {
            return flow;
        }
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0)
        {
            flow+=f;
        }
    }
}
int vertix_count,visited[5020];
void solve(int v)
{
    ++vertix_count;
    visited[v]=1;
    for(int i=0;i<G[v].size();++i)
    {
        edge &e=G[v][i];
        if(e.cap>0&&!visited[e.to])
        {
            solve(e.to);
        }
    }
}
int N,M;
int main()
{
    scanf("%d%d",&N,&M);
    ll W=0;
    for(int i=1;i<=N;++i)
    {
        ll tmp;
        scanf("%lld",&tmp);
        if(tmp>0)
        {
            W+=tmp;
            add_edge(0,i,tmp);
        }
        if(tmp<0)
        {
            add_edge(i,N+1,-tmp);
        }
    }
    for(int i=0;i<M;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v,INF);
    }
    ll ans=W-max_flow(0,N+1);
    solve(0);
    printf("%d %lld",--vertix_count,ans);
    return 0;
}