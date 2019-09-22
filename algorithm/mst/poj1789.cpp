#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=30020;
const int MAXM=2000020;
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
char tru[2010][10];
int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        int num=0;
        for(int i=0;i<n;++i)
        {
            scanf("%s",tru[i]);
            for(int j=0;j<i;++j)
            {
                int tmp=0;
                for(int t=0;t<7;++t)
                {
                    if(tru[i][t]!=tru[j][t])
                    {
                        ++tmp;
                    }
                }
                edges[num].from=i,edges[num].to=j,edges[num++].cost=tmp;
            }
        }
        int ans=mst(n,num);
        printf("The highest possible quality is 1/%d.\n",ans);
    }
    return 0;
}
