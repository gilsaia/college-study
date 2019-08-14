#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=3002;
int par[MAXN];
bool tofind[MAXN];
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
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(tofind,0,sizeof(tofind));
        int n,m;
        scanf("%d%d",&n,&m);
        init(n);
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            unite(a,b);
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            int root=find(i);
            if(!tofind[root])
            {
                ++ans;
                tofind[root]=true;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}