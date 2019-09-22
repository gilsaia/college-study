#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=30020;
const int MAXM=1000020;
int par[MAXN];
void init(int n)
{
    for(int i=0;i<=n;++i)
    {
        par[i]=i;
    }
}
int find(int x)
{
    if(x==par[x])
    {
        return x;
    }
    return par[x]=find(par[x]);
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    par[x]=y;
}
struct edge
{
    int from,to,cost;
    bool operator<(const edge &rhs) const
    {
        return cost<rhs.cost;
    }
};
edge edges[MAXM];
void mst(int n,int m)
{
    sort(edges,edges+m);
    for(int i=0;i<m;++i)
    {
        if(!same(edges[i].from,edges[i].to))
        {
            unite(edges[i].from,edges[i].to);
            printf("%d %d\n",edges[i].from,edges[i].to);
        }
    }
    return;
}
int x[820],y[820];
int main()
{
    int n;
    scanf("%d",&n);
    init(n);
    int num=0;
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",&x[i],&y[i]);
        for(int j=0;j<i;++j)
        {
            int dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            edges[num].from=j+1,edges[num].to=i+1,edges[num++].cost=dis;
        }
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        unite(a,b);
    }
    mst(n,num);
    return 0;
}