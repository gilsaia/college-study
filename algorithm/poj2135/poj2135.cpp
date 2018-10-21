//例题···一个不是很好想到的最小费用流
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
vector<edge> G[1050];
int h[1050];
int dist[1050];
int prevv[1050],preve[1050];
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
int main()
{
    scanf("%d%d",&N,&M);
    int s=0,t=N-1;
    V=N;
    for(int i=0;i<M;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        --a,--b;
        add_edge(a,b,1,c);
        add_edge(b,a,1,c);
    }
    printf("%d\n",min_cost_flow(s,t,2));
    return 0;
}