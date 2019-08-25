#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=300020;
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
vector<int> layer[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        int n,m,c;
        scanf("%d%d%d",&n,&m,&c);
        dijkstra.init(n*3+1);
        for(int i=0;i<=n;++i)
        {
            layer[i].clear();
        }
        for(int i=1;i<=n;++i)
        {
            int tmp;
            scanf("%d",&tmp);
            layer[tmp].push_back(i);
            dijkstra.AddEdge(i,tmp+n,0);
            dijkstra.AddEdge(tmp+n*2,i,0);
        }
        for(int i=1;i<n;++i)
        {
            if((!layer[i].empty())&&(!layer[i+1].empty()))
            {
                dijkstra.AddEdge(i+n,i+n*2+1,c);
                dijkstra.AddEdge(i+1+n,i+n*2,c);
            }
        }
        for(int i=0;i<m;++i)
        {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            dijkstra.AddEdge(u,v,d);
            dijkstra.AddEdge(v,u,d);
        }
        dijkstra.dijkstra(1);
        printf("Case #%d: ",t);
        if(dijkstra.d[n]!=inf)
        {
            printf("%d\n",dijkstra.d[n]);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}