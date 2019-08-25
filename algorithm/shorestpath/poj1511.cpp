#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1000020;
const int inf=0x3f3f3f3f;
struct Edge{
    int from,to,dist;
    Edge(int u=0,int v=0,int d=0):from(u),to(v),dist(d){}
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
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        dijkstra.init(n+1);
        for(int i=0;i<m;++i)
        {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            dijkstra.AddEdge(u,v,d);
        }
        dijkstra.dijkstra(1);
        ll ans=0;
        for(int i=2;i<=n;++i)
        {
            ans+=dijkstra.d[i];
        }
        for(int i=1;i<=n;++i)
        {
            dijkstra.G[i].clear();
        }
        for(int i=0;i<dijkstra.edges.size();++i)
        {
            swap(dijkstra.edges[i].from,dijkstra.edges[i].to);
            dijkstra.G[dijkstra.edges[i].from].push_back(i);
        }
        dijkstra.dijkstra(1);
        for(int i=2;i<=n;++i)
        {
            ans+=dijkstra.d[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}