//最小费用流问题···emmmm建图时候我是考虑的每个点自己有一条容量为一费用为其值的边还有一条容量无穷大的边，再将相邻关系连好即可···注意为了求最大值所以我变成负数后加上一个足够大的值···还有点自身的容量限制要怎么做就是很标准的书上解法了···
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<functional>
using namespace std;
const int INF=1e9;
const int ADD=1200;
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
int N,K;
int map[70][70];
int main()
{
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            scanf("%d",&map[i][j]);
        }
    }
    int n=N*N,s=0,t=n*2-1;
    V=t+1;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            add_edge(i*N+j,n+i*N+j,1,-map[i][j]+ADD);
            add_edge(i*N+j,n+i*N+j,INF,ADD);
            if(i!=N-1)
            {
                add_edge(n+i*N+j,(i+1)*N+j,INF,0);
            }
            if(j!=N-1)
            {
                add_edge(n+i*N+j,i*N+j+1,INF,0);
            }
        }
    }
    int res=min_cost_flow(s,t,K);
    res-=ADD*(N*2-1)*K;
    res=-res;
    printf("%d\n",res);
    return 0;
}