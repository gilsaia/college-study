#include<cstdio>
#include<algorithm>
using namespace std;
int par[100020];
void init(int n)
{
    for(int i=0;i<=n;++i)
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
    par[x]=y;
}
int appear[100020][2],index[100020];
int main()
{
    int M,N;
    scanf("%d%d",&M,&N);
    init(M);
    for(int i=0;i<M;++i)
    {
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;++j)
        {
            int tmp;
            scanf("%d",&tmp);
            appear[tmp][index[tmp]++]=i;
        }
    }
    int ans=0;
    for(int i=1;i<=N;++i)
    {
        if(!same(appear[i][0],appear[i][1]))
        {
            ++ans;
            unite(appear[i][0],appear[i][1]);
        }
    }
    printf("%d\n",ans);
    return 0;
}