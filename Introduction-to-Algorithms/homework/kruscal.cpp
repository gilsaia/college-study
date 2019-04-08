#include<cstdio>
#include<algorithm>
using namespace std;
int par[60];
void init(int n)
{
    for(int i=0;i<n;++i)
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
bool same(int x,int y)
{
    return find(x)==find(y);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    par[x]=par[y];
}
struct edge
{
    int u,v,value;
};
bool cmp(edge a,edge b)
{
    return a.value<b.value;
}
edge edges[1030];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].value);
    }
    init(n+1);
    sort(edges,edges+m,cmp);
    int choose=1,num=0,ans=0;
    while(choose<n)
    {
        if(same(edges[num].u,edges[num].v))
        {
            ++num;
            continue;
        }
        ans+=edges[num].value;
        unite(edges[num].u,edges[num].v);
        ++choose;
        ++num;
    }
    printf("%d\n",ans);
    return 0;
}