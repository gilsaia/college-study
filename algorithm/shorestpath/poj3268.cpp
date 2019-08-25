#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1020;
const int inf=0x3f3f3f3f;
struct Edge{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
    Edge(){}
};
struct Dijkstra{
    int n,m;
    vector<Edge> edges;
    vector<int > G[maxn];
    bool done[maxn];   //永久标记
    int d[maxn];    //s到各点距离
    int p[maxn];
    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int dist){
        edges.push_back(Edge(from,to,dist));
        m=edges.size();
        G[from].push_back(m-1);
    }
    struct HeapNode{
        int d,u;
        bool operator < (const HeapNode& rhs) const{
            return d>rhs.d;
        }
        HeapNode(int dt,int ut)
        {
            d=dt;
            u=ut;
        }
    };
    void dijkstra(int s){
        priority_queue<HeapNode> Q;
        for(int i=0;i<n;i++) d[i]=inf;
        d[s]=0;
        memset(done,0,sizeof(done));
        Q.push(HeapNode{0,s});
        while(!Q.empty()){
            HeapNode x=Q.top();Q.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=true;
            for(int i=0;i<G[u].size();i++){
                Edge& e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    HeapNode tmp(d[e.to],e.to);
                    Q.push(tmp);
                }
            }
        }
    }
}dijkstra;
int from[maxn],to[maxn];
Edge edg[100020];
int main()
{
    int N,M,X;
    scanf("%d%d%d",&N,&M,&X);
    dijkstra.init(N+1);
    for(int i=0;i<M;++i)
    {
        scanf("%d%d%d",&edg[i].from,&edg[i].to,&edg[i].dist);
        dijkstra.AddEdge(edg[i].from,edg[i].to,edg[i].dist);
    }
    dijkstra.dijkstra(X);
    for(int i=1;i<=N;++i)
    {
        from[i]=dijkstra.d[i];
    }
    dijkstra.init(N+1);
    for(int i=0;i<M;++i)
    {
        dijkstra.AddEdge(edg[i].to,edg[i].from,edg[i].dist);
    }
    dijkstra.dijkstra(X);
    int ans=0;
    for(int i=1;i<=N;++i)
    {
        ans=max(ans,from[i]+dijkstra.d[i]);
    }
    printf("%d\n",ans);
    return 0;
}