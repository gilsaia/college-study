#include <cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
 
const int oo=1e9;//无穷大
const int maxm=200020;//边的最大数量，为原图的两倍
const int maxn=5040;//点的最大数量
 
int node,src,dest,edge;//node节点数，src源点，dest汇点，edge边数
int head[maxn],p[maxn],dis[maxn],q[maxn],vis[maxn];//head链表头，p记录可行流上节点对应的反向边，dis计算距离
 
struct edgenode
{
    int to;//边的指向
    int flow;//边的容量
    int cost;//边的费用
    int next;//链表的下一条边
} edges[maxm];
 
void prepare(int _node,int _src,int _dest);
void addedge(int u,int v,int f,int c);
bool spfa();

 
inline void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    edge=0;
}
 
void addedge(int u,int v,int f,int c)
{
    edges[edge].flow=f;
    edges[edge].cost=c;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
    edges[edge].flow=0;
    edges[edge].cost=-c;
    edges[edge].to=u;
    edges[edge].next=head[v];
    head[v]=edge++;
}
 
bool spfa()
{
    int i,u,v,l,r=0,tmp;
    for (i=0; i<node; i++) dis[i]=oo;
    dis[q[r++]=src]=0;
    p[src]=p[dest]=-1;
    for (l=0; l!=r; ((++l>=maxn)?l=0:1))
    {
        for (i=head[u=q[l]],vis[u]=false; i!=-1; i=edges[i].next)
        {
            if (edges[i].flow&&dis[v=edges[i].to]>(tmp=dis[u]+edges[i].cost))
            {
                dis[v]=tmp;
                p[v]=i^1;
                if (vis[v]) continue;
                vis[q[r++]=v]=true;
                if (r>=maxn) r=0;
            }
        }
    }
    return p[dest]>=0;
}
 
int spfaflow()
{
    int i,ret=0,delta;
    while (spfa())
    {
        //按记录原路返回求流量
 
        for (i=p[dest],delta=oo; i>=0; i=p[edges[i].to])
        {
            delta=min(delta,edges[i^1].flow);
        }
        for (int i=p[dest]; i>=0; i=p[edges[i].to])
        {
            edges[i].flow+=delta;
            edges[i^1].flow-=delta;
        }
        ret+=delta*dis[dest];
    }
    return ret;
}
int main()
{
    int N,M,K,start,end;
    while(scanf("%d%d%d",&N,&M,&K),N+M+K)
    {
        start=0,end=(N+M)*K+1;
        prepare((N+M)*K+2,start,end);//对每种商品 1-N 售货员 N+1-N+M 仓库
        for(int i=1;i<=N;++i)
        {
            for(int j=0;j<K;++j)
            {
                int baseadd=(N+M)*j;
                int tmp;
                scanf("%d",&tmp);
                addedge(baseadd+i,end,tmp,0);
            }
        }
        for(int i=1;i<=M;++i)
        {
            for(int j=0;j<K;++j)
            {
                int baseadd=(N+M)*j;
                int tmp;
                scanf("%d",&tmp);
                addedge(start,baseadd+N+i,tmp,0);
            }
        }
        for(int i=0;i<K;++i)
        {
            int baseadd=(N+M)*i;
            for(int j=1;j<=N;++j)
            {
                for(int t=1;t<=M;++t)
                {
                    int tmp;
                    scanf("%d",&tmp);
                    addedge(baseadd+N+t,baseadd+j,oo,tmp);
                }
            }
        }
        int res=spfaflow();
        bool achieve=true;
        for(int i=0;i<N;++i)
        {
            if(edges[i].flow!=0)
            {
                achieve=false;
                break;
            }
        }
        if(!achieve)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",res);
        }
    }
    return 0;
}