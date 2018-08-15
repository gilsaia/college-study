//还是最基础的最小生成树问题，把最小改为最大即可顺便别忘了加一个是否能成树的判定，目前来说kruskal算法我只能讲并查集模块和算法模块分开写
//还有努力进步的空间
#include<stdio.h>
#include<algorithm>
using namespace std;
struct edge
{
    int from,to,cost;
};
bool cmp(edge a,edge b)
{
    return a.cost>b.cost;
}
edge es[20010];
int par[1010];
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
    return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
    {
        return;
    }
    else
    {
        par[x]=y;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&es[i].from,&es[i].to,&es[i].cost);
    }
    sort(es,es+m,cmp);
    int ans=0,used=0;
    for(int i=0;i<m;i++)
    {
        if(!same(es[i].from,es[i].to))
        {
            unite(es[i].from,es[i].to);
            ans+=es[i].cost;
            used++;
        }
    }
    if(used!=n-1)
    {
        ans=-1;
    }
    printf("%d\n",ans);
    return 0;
}