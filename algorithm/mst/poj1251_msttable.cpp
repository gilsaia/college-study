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
int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        int num=0;
        for(int i=1;i<n;++i)
        {
            char fro[2];
            scanf("%s",fro);
            int from=fro[0]-'A';
            int m;
            scanf("%d",&m);
            for(int j=0;j<m;++j)
            {
                char to[2];
                int val;
                scanf("%s %d",to,&val);
                int tod=to[0]-'A';
                edges[num+j].from=from;
                edges[num+j].to=tod;
                edges[num+j].cost=val;
            }
            num+=m;
        }
        int ans=mst(n,num);
        printf("%d\n",ans);
    }
    return 0;
}