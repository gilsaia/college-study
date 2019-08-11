#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=30020;
const int maxm=150020;
const int inf=0x3f3f3f3f;
struct Edge{
    int from,to,dist,next;
    Edge(int u=0,int v=0,int d=0):from(u),to(v),dist(d){}
};
struct Dijkstra{
    int n,m;
    Edge edges[maxm];
    int G[maxn];
    bool done[maxn];   //永久标记
    int d[maxn];    //s到各点距离
    int p[maxn];
    void init(int n){
        this->n=n;
        m=1;
        memset(G,0,sizeof(G));
    }
    void AddEdge(int from,int to,int dist){
        edges[m]=Edge(from,to,dist);
        edges[m].next=G[from];
        G[from]=m;
        ++m;
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
            for(int i=G[u];i!=0;i=edges[i].next){
                Edge& e=edges[i];
                if(d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=i;
                    HeapNode tmp(d[e.to],e.to);
                    Q.push(tmp);
                }
            }
        }
    }
}dijkstra;
int main()
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
    int ans=dijkstra.d[n];
    printf("%d\n",ans);
    return 0;
}