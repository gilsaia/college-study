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
    memset(p,0,sizeof(p));
    memset(q,0,sizeof(q));
    memset(dis,0,sizeof(dis));
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
int shoper[100][100];
int castle[100][100];
int need[120];
int have[120];
int main()
{
    int N,M,K,start,end;
    while(scanf("%d%d%d",&N,&M,&K),N+M+K)
    {
        memset(shoper,0,sizeof(shoper));
        memset(castle,0,sizeof(castle));
        memset(need,0,sizeof(need));
        memset(have,0,sizeof(have));
        for(int i=1;i<=N;++i)
        {
            for(int j=0;j<K;++j)
            {
                int tmp;
                scanf("%d",&tmp);
                shoper[j][i]=tmp;
                need[j]+=tmp;
            }
        }
        for(int i=1;i<=M;++i)
        {
            for(int j=0;j<K;++j)
            {
                int tmp;
                scanf("%d",&tmp);
                castle[j][i]=tmp;
                have[j]+=tmp;
            }
        }
        int ans=0;
        bool achieve=true;
        for(int i=0;i<K;++i)
        {
            if(need[i]>have[i])
            {
                achieve=false;
            }
            int start=0,end=(N+M)+1;
            prepare(end+1,start,end);
            for(int j=1;j<=N;++j)
            {
                if(shoper[i][j]!=0)
                {
                    addedge(j,end,shoper[i][j],0); 
                }
            }
            for(int j=1;j<=M;++j)
            {
                if(castle[i][j]!=0)
                {
                    addedge(start,N+j,castle[i][j],0);
                }
            }
            for(int j=1;j<=N;++j)
            {
                for(int t=1;t<=M;++t)
                {
                    int tmp;
                    scanf("%d",&tmp);
                    addedge(N+t,j,oo,tmp);
                }
            }
            if(!achieve)
            {
                continue;
            }
            ans+=spfaflow();
        }
        if(!achieve)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
    return 0;
}