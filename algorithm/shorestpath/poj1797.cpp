#include<cstdio>
#include<algorithm>
using namespace std;
int par[1200];
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
    x=find(x),y=find(y);
    par[x]=y;
}
struct node
{
    int a,b,val;
};
bool cmp(node a,node b)
{
    return a.val>b.val;
}
node edge[1000030];
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        init(n);
        for(int j=0;j<m;++j)
        {
            scanf("%d%d%d",&edge[j].a,&edge[j].b,&edge[j].val);
        }
        sort(edge,edge+m,cmp);
        int ans=0x3f3f3f3f;
        for(int j=0;j<m;++j)
        {
            if(same(1,n))
            {
                break;
            }
            ans=edge[j].val;
            if(!same(edge[j].a,edge[j].b))
            {
                unite(edge[j].a,edge[j].b);
            }
        }
        printf("Scenario #%d:\n%d\n\n",i,ans);
    }
    return 0;
}