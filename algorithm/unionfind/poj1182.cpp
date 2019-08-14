#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=200020;
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
    int N,K;
    scanf("%d%d",&N,&K);
    init(N*3);
    int ans=0;
    for(int i=0;i<K;++i)
    {
        int op,a,b;
        scanf("%d%d%d",&op,&a,&b);
        if(a>N||b>N||a<=0||b<=0)
        {
            ++ans;
            continue;
        }
        if(op==1)
        {
            if(same(a,N+b)||same(a,2*N+b))
            {
                ++ans;
            }
            else
            {
                unite(a,b);
                unite(N+a,N+b);
                unite(2*N+a,2*N+b);
            }
        }
        else
        {
            if(same(a,b)||same(a,2*N+b))
            {
                ++ans;
            }
            else
            {
                unite(a,N+b);
                unite(N+a,2*N+b);
                unite(2*N+a,b);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}