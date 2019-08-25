#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1020;
const int inf=0x3f3f3f3f;
int edges[320][320];
struct Edge{
    int from,to,dist;
    Edge(int u=0,int v=0,int d=0):from(u),to(v),dist(d){}
};
struct Dijkstra{
    int n,m,cir;
    bool done[maxn];   //永久标记
    int d[maxn];    //s到各点距离
    int p[maxn];
    void init(int n){
        this->n=n;
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
        cir=inf;
        Q.push(HeapNode{0,s});
        while(!Q.empty()){
            HeapNode x=Q.top();Q.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=true;
            for(int i=0;i<n;i++){
                if(d[i]>d[u]+edges[u][i]){
                    d[i]=d[u]+edges[u][i];
                    p[i]=u;
                    HeapNode tmp(d[i],i);
                    Q.push(tmp);
                }
            }
        }
    }
}dijkstra;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d",&edges[i][j]);
            }
        }
        dijkstra.init(n);
        dijkstra.dijkstra(0);
        int ans=dijkstra.d[n-1];
        int cir1=inf;
        for(int i=1;i<n;++i)
        {
            cir1=min(cir1,dijkstra.d[i]+edges[i][0]);
        }
        dijkstra.dijkstra(n-1);
        int cir2=inf;
        for(int i=0;i<(n-1);++i)
        {
            cir2=min(cir2,dijkstra.d[i]+edges[i][n-1]);
        }
        printf("%d\n",min(ans,cir1+cir2));
    }
    return 0;
}