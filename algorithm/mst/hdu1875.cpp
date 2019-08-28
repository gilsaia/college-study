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
    int edgeuse=0;
    for(int i=0;i<m;++i)
    {
        if(!same(edges[i].from,edges[i].to))
        {
            ans+=edges[i].cost;
            unite(edges[i].from,edges[i].to);
            ++edgeuse;
        }
    }
    if(edgeuse!=(n-1))
    {
        return -1;
    }
    return ans;
}
int x[120],y[120];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int num=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&x[i],&y[i]);
            for(int j=0;j<i;++j)
            {
                double dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                dis=sqrt(dis);
                if(dis>=10&&dis<=1000)
                {
                    edges[num].from=i,edges[num].to=j,edges[num++].cost=dis;
                }
            }
        }
        double ans=mst(n,num);
        if(ans==-1)
        {
            printf("oh!\n");
        }
        else
        {
            ans*=100;
            printf("%.1lf\n",ans);
        }
    }
    return 0;
}