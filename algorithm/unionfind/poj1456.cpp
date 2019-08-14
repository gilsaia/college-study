#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=30020;
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
struct node
{
    int p,d;
};
bool cmp(node a,node b)
{
    return a.p>b.p;
}
node sell[10020];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        init(10001);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&sell[i].p,&sell[i].d);
        }
        sort(sell,sell+n,cmp);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int root=find(sell[i].d);
            if(root>0)
            {
                ans+=sell[i].p;
                unite(root,root-1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}