#include<cstdio>
#include<algorithm>
#include<cmath>
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
    int from,to;
    double cost;
    bool operator<(const edge &rhs) const
    {
        return cost<rhs.cost;
    }
};
edge edges[MAXM];
double mst(int n,int m)
{
    init(n);
    sort(edges,edges+m);
    double ans=0;
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
double x[120],y[120],z[120],r[120];
int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%lf%lf%lf%lf",&x[i],&y[i],&z[i],&r[i]);
        }
        int num=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                double dis=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]))-r[i]-r[j];
                if(dis<=0)
                {
                    dis=0;
                }
                edges[num].from=i,edges[num].to=j,edges[num++].cost=dis;
            }
        }
        double ans=mst(n,num);
        printf("%.3lf\n",ans);
    }
    return 0;
}