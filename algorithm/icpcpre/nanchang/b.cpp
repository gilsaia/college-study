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
    int maxdis;
    void init(int n){
        this->n=n;
        for(int i=0;i<=n;i++) G[i].clear();
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
        maxdis=0;
        priority_queue<HeapNode> Q;
        for(int i=0;i<=n;i++) d[i]=inf;
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
        for(int i=1;i<=n;++i)
        {
            maxdis=max(maxdis,d[i]);
        }
    }
}dijkstra;
int team[1020];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,e,s,k,c;
        scanf("%d%d%d%d%d",&n,&e,&s,&k,&c);
        dijkstra.init(n);
        for(int i=0;i<k;++i)
        {
            int tmp;
            scanf("%d",&tmp);
            dijkstra.AddEdge(0,tmp,0);
        }
        for(int i=0;i<e;++i)
        {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            dijkstra.AddEdge(u,v,d);
            dijkstra.AddEdge(v,u,d);
        }
        dijkstra.dijkstra(s);
        int herodis=dijkstra.maxdis;
        int teamdis=0;
        dijkstra.dijkstra(0);
        teamdis=dijkstra.maxdis;
        double tmp=herodis;
        tmp/=(double)c;
        if(tmp<=teamdis)
        {
            printf("%d\n",herodis);
        }
        else
        {
            printf("%d\n",teamdis);
        }
    }
    return 0;
}