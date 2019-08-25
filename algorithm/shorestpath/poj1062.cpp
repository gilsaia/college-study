#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1020;
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
    int value[maxn];
    int levmax,levmin;
    int level[maxn];
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
        d[s]=value[s];
        memset(done,0,sizeof(done));
        Q.push(HeapNode{0,s});
        while(!Q.empty()){
            HeapNode x=Q.top();Q.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=true;
            for(int i=0;i<G[u].size();i++){
                Edge& e=edges[G[u][i]];
                int tmp=d[u]-value[u]+e.dist+value[e.to];
                if(d[e.to]>tmp&&level[e.to]>=levmin&&level[e.to]<=levmax){
                    d[e.to]=tmp;
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
    int M,N;
    scanf("%d%d",&M,&N);
    dijkstra.init(N+1);
    for(int i=1;i<=N;++i)
    {
        int m;
        scanf("%d%d%d",&dijkstra.value[i],&dijkstra.level[i],&m);
        for(int j=0;j<m;++j)
        {
            int to,dis;
            scanf("%d%d",&to,&dis);
            dijkstra.AddEdge(i,to,dis);
        }
    }
    dijkstra.levmin=dijkstra.level[1]-M,dijkstra.levmax=dijkstra.level[1]+M;
    dijkstra.dijkstra(1);
    int ans=dijkstra.d[1];
    for(int i=1;i<=N;++i)
    {
        ans=min(ans,dijkstra.d[i]);
    }
    printf("%d\n",ans);
    return 0;
}