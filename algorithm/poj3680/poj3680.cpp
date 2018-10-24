//最小费用流的例题···
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
int N,K;
int a[220],b[220],w[220];
void solve()
{
    vector<int> x;
    for(int i=0;i<N;++i)
    {
        x.push_back(a[i]);
        x.push_back(b[i]);
    }
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    int m=x.size();
    int s=m,t=s+1;
    V=t+1;
    int res=0;
    add_edge(s,0,K,0);
    add_edge(m-1,t,K,0);
    for(int i=0;i+1<m;++i)
    {
        add_edge(i,i+1,INF,0);
    }
    for(int i=0;i<N;++i)
    {
        int u=find(x.begin(),x.end(),a[i])-x.begin();
        int v=find(x.begin(),x.end(),b[i])-x.begin();
        add_edge(v,u,1,w[i]);
        add_edge(s,v,1,0);
        add_edge(u,t,1,0);
        res-=w[i];
    }
    res+=min_cost_flow(s,t,K+N);
    printf("%d\n",-res);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<V;++i)
        {
            G[i].clear();
        }
        scanf("%d%d",&N,&K);
        for(int i=0;i<N;++i)
        {
            scanf("%d%d%d",&a[i],&b[i],&w[i]);
        }
        solve();
    }
    return 0;
}