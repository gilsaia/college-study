//这个题题意有点复杂一开始差点没看懂····emmmmmmmm好吧是看题解才知道题意啥意思的···
//最后还是最小生成树模板求其中最长的一条边即可
#include<stdio.h>
#include<algorithm>
using namespace std;
struct edge
{
    int u,v,cost;
};
bool cmp(edge a,edge b)
{
    return a.cost<b.cost;
}
edge es[10010];
int par[2010];
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
    par[x]=y;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    init(N);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
    }
    sort(es,es+M,cmp);
    int ans=0;
    for(int i=0;i<M;i++)
    {
        if(!same(es[i].u,es[i].v))
        {
            unite(es[i].u,es[i].v);
            ans=max(es[i].cost,ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}