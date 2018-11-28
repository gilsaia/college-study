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
ll weight[1030];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int s=0,t=n+m+1;
    for(int i=1;i<=n;++i)
    {
        scanf("%I64d",&weight[i]);
        add_edge(i,t,weight[i]);
    }
    int u,v;
    ll sum=0;
    for(int i=1;i<=m;++i)
    {
        ll tmp;
        scanf("%d%d%I64d",&u,&v,&tmp);
        sum+=tmp;
        add_edge(s,i+n,tmp);
        add_edge(i+n,u,INF);
        add_edge(i+n,v,INF);
    }
    printf("%I64d\n",sum-max_flow(s,t));
    return 0;
}