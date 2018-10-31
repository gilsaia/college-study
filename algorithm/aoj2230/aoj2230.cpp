//最小费用流问题···我直接粘题解吧···
/*如果将原DAG权值取反，然后从最后一关连一条正权边到第一关，权值是最短路（负权值最短路=传统意义上的最长路）的长度的话，那么那些正圈中的负权边就是应该增加权值的边，具体应该加多少，就是正圈的权值。

再看怎么用网络流计算这些正圈权值，新建源点汇点，对于所有顶点，如果入度>出度，从源点连一条边到它，否则，从它连一条边到汇点，容量都是是度数差。
在上面跑F=源点cap总和的最小费用流，得到的就是每个圈的正边（红色）权值之和，在将其加上所有圈的负边（蓝色）之和，就是所有正圈的权值之和，也就是最终答案。*/
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
vector<edge> G[505];
int h[505];
int dist[505];
int prevv[505],preve[505];
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
int N,M,s,t;
int indree[520],outdree[520];
int main()
{
    scanf("%d%d",&N,&M);
    V=N+2;
    t=N+1;
    int total=0;
    for(int i=1;i<=M;++i)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        ++x,++y;
        add_edge(x,y,INF,-z);
        outdree[x]++,indree[y]++;
        total+=z;
    }
    int max_f=0;
    for(int i=1;i<=N;++i)
    {
        if(indree[i]>outdree[i])
        {
            add_edge(s,i,indree[i]-outdree[i],0);
            max_f+=indree[i]-outdree[i];
        }
        else
        {
            add_edge(i,t,outdree[i]-indree[i],0);
        }
    }
    min_cost_flow(1,N,1);
    add_edge(N,1,INF,-dist[N]);
    int ans=min_cost_flow(s,t,max_f);
    printf("%d\n",ans-total);
    return 0;
}