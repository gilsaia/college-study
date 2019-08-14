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
int main()
{
    int n,m;
    int group[30020];
    while(~scanf("%d%d",&n,&m),n)
    {
        init(n);
        for(int i=0;i<m;++i)
        {
            int k;
            scanf("%d",&k);
            for(int j=0;j<k;++j)
            {
                scanf("%d",&group[j]);
            }
            for(int j=1;j<k;++j)
            {
                unite(group[j],group[j-1]);   
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(same(0,i))
            {
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}