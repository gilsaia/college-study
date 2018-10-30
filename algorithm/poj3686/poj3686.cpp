#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<functional>
using namespace std;
const int INF=1e9;
typedef pair<int,int> P;
struct edge
{
    int to,cap,cost,rev;
};
int V;
vector<edge> G[5050];
int h[5050];
int dist[5050];
int prevv[5050],preve[5050];
void add_edge(int from,int to,int cap,int cost)
{
    edge tmp;
    tmp.to=to,tmp.cap=cap,tmp.cost=cost,tmp.rev=G[to].size();
    G[from].push_back(tmp);
    tmp.to=from,tmp.cap=0,tmp.cost=-cost,tmp.rev=G[from].size()-1;
    G[to].push_back(tmp);
}
int min_cost_flow(int s,int t,int f)
{
    int res=0;
    fill(h,h+V,0);
    while(f>0)
    {
        priority_queue<P,vector<P>,greater<P>> que;
        fill(dist,dist+V,INF);
        dist[s]=0;
        que.push(P(0,s));
        while(!que.empty())
        {
            P p=que.top();
            que.pop();
            int v=p.second;
            if(dist[v]<p.first)
            {
                continue;
            }
            for(int i=0;i<G[v].size();++i)
            {
                edge &e=G[v][i];
                if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
                {
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t]==INF)
        {
            return -1;
        }
        for(int v=0;v<V;++v)
        {
            h[v]+=dist[v];
        }
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
int N,M;
int Z[60][60];
void solve()
{
    int s=N+N*M,t=s+1;
    V=t+1;
    for(int i=0;i<N;++i)
    {
        add_edge(s,i,1,0);
    }
    for(int j=0;j<M;++j)
    {
        for(int k=0;k<N;++k)
        {
            add_edge(N+j*N+k,t,1,0);
            for(int i=0;i<N;++i)
            {
                add_edge(i,N+j*N+k,1,(k+1)*Z[i][j]);
            }
        }
    }
    printf("%.6f\n",(double)min_cost_flow(s,t,N)/N);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<=V;++i)
        {
            G[i].clear();
        }
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<M;++j)
            {
                scanf("%d",&Z[i][j]);
            }
        }
        solve();
    }
    return 0;
}