#include<cstdio>
#include<algorithm>
#include<cmath>
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
int mst(int n,int m,int s)
{
    init(n);
    sort(edges,edges+m);
    int ans=0;
    int achieve=n-s;
    for(int i=0;i<m;++i)
    {
        if(!same(edges[i].from,edges[i].to))
        {
            ans=max(ans,edges[i].cost);
            unite(edges[i].from,edges[i].to);
            if((--achieve)==0)
            {
                break;
            }
        }
    }
    return ans;
}
int x[520],y[520];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int s,n;
        scanf("%d%d",&s,&n);
        int num=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&x[i],&y[i]);
            for(int j=0;j<i;++j)
            {
                int dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                edges[num].from=i,edges[num].to=j,edges[num++].cost=dis;
            }
        }
        int ans=mst(n,num,s);
        double tmp=ans;
        tmp=sqrt(tmp);
        printf("%.2lf\n",tmp);
    }
    return 0;
}