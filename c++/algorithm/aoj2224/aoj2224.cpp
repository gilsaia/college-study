//严格来说还是用了提示的··书里说明了这是最小生成树的题然后画了几个样例猜到了方法··
//其实很简单，开始给的坐标是算距离的，后面给的图连起来后找最大生成树，没用到的所有花费加起来就是要求的了··
//原理似乎是因为有了最大生成树之后任何一条新的边加进来都会形成圈，所以找到会形成圈的最小边拿圣水轰掉就好··
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct edge
{
    int u,v;
    double cost;
};
bool cmp(edge a,edge b)
{
    return a.cost>b.cost;
}
edge es[100000];
bool used[100000];
int par[10010];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
    }
}
int find(int x)
{
    if(par[x]==x)
    {
        return x;
    }
    else
    {
        return par[x]=find(par[x]);
    }
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
    {
        return;
    }
    par[y]=x;
    return;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
struct position
{
    int x,y;
};
position pos[10010];
void calute(edge &a)
{
    double tempx=pos[a.u].x-pos[a.v].x;
    double tempy=pos[a.u].y-pos[a.v].y;
    tempx*=tempx;
    tempy*=tempy;
    tempx+=tempy;
    a.cost=sqrt(tempx);
}
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    init(N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&pos[i].x,&pos[i].y);
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&es[i].u,&es[i].v);
        calute(es[i]);
    }
    sort(es,es+M,cmp);
    double ans=0;
    for(int i=0;i<M;i++)
    {
        if(!same(es[i].u,es[i].v))
        {
            unite(es[i].u,es[i].v);
            used[i]=1;
        }
        else
        {
            ans+=es[i].cost;
        }
    }
    printf("%lf\n",ans);
    return 0;
}