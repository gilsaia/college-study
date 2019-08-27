#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10020;
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
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        init(n*2);
        int can=1;
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(can)
            {
                if(same(a,b))
                {
                    can=0;
                    continue;
                }
                unite(a,b+n);
                unite(a+n,b);
            }
        }
        printf("Scenario #%d:\n",t);
        if(can)
        {
            printf("No suspicious bugs found!\n");
        }
        else
        {
            printf("Suspicious bugs found!\n");
        }
        printf("\n");
    }
    return 0;
}