#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1020;
const int inf=0x3f3f3f3f;
struct Edge{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
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
                int tmp=max(d[u],e.dist);
                if(d[e.to]>tmp){
                    d[e.to]=tmp;
                    p[e.to]=G[u][i];
                    HeapNode tmp(d[e.to],e.to);
                    Q.push(tmp);
                }
            }
        }
    }
}dijkstra;
struct point
{
    int x,y;
};
int cal(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
point stone[1020];
int main()
{
    int n;
    int num=1;
    while(scanf("%d",&n),n)
    {
        dijkstra.init(n);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&stone[i].x,&stone[i].y);
        }
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int dis=cal(stone[i],stone[j]);
                dijkstra.AddEdge(i,j,dis);
                dijkstra.AddEdge(j,i,dis);
            }
        }
        dijkstra.dijkstra(0);
        double dis=sqrt(dijkstra.d[1]);
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",num++,dis);
    }
    return 0;
}