#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1020;
const int inf=0x3f3f3f3f;
struct edge{
    int from,to,dist;
    edge(int u=0,int v=0,int d=0):from(u),to(v),dist(d){}
};
struct Dijkstra{
    int n,m;
    vector<edge> edges;
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
        edges.push_back(edge(from,to,dist));
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
                edge& e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    HeapNode tmp(d[e.to],e.to);
                    Q.push(tmp);
                }
            }
        }
    }
}dij,dij2;
const int MAXV = 2005;
const int INF = 0x3f3f3f3f;
struct Edge{ int to, cap, rev; };
vector<Edge> G[MAXV];
int level[MAXV];
int iter[MAXV]; //当前弧，之前的已经没有用了

void addedge(int from, int to, int cap) {
    G[from].push_back(Edge{to, cap, G[to].size()});
    G[to].push_back(Edge{from, 0, G[from].size()-1});
}

void bfs(int s) {
    memset(level, -1, sizeof level);
    std::queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            Edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); ++i) { // 注意i是引用 实现当前弧优化
        Edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, std::min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    for (; ;) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof iter);
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
    return flow;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        dij.init(n+1);
        dij2.init(n+1);
        for(int i=0;i<=n;++i)
        {
            G[i].clear();
        }
        for(int i=0;i<m;++i)
        {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            dij.AddEdge(u,v,d);
            dij2.AddEdge(v,u,d);
        }
        int s,t;
        scanf("%d%d",&s,&t);
        dij.dijkstra(s);
        dij2.dijkstra(t);
        int _min=dij.d[t];
        for(int i=0;i<dij.edges.size();++i)
        {
            if((dij.d[dij.edges[i].from]+dij2.d[dij.edges[i].to]+dij.edges[i].dist)==_min)
            {
                addedge(dij.edges[i].from,dij.edges[i].to,1);
            }
        }
        int ans=maxflow(s,t);
        printf("%d\n",ans);
    }
}