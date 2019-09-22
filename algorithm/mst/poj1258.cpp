#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=30020;
const int MAXM=10020;
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
int mst(int n,int m)
{
    init(n);
    sort(edges,edges+m);
    int ans=0;
    for(int i=0;i<m;++i)
    {
        if(!same(edges[i].from,edges[i].to))
        {
            ans+=edges[i].cost;
            unite(edges[i].from,edges[i].to);
        }
    }
    return ans;
}
int dis[120][120];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d",&dis[i][j]);
            }
        }
        int num=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                edges[num].from=i,edges[num].to=j,edges[num++].cost=dis[i][j];
            }
        }
        int ans=mst(n,num);
        printf("%d\n",ans);
    }
    return 0;
}