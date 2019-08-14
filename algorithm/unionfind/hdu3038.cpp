#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300200;
int par[MAXN],val[MAXN];
void init()
{
    memset(par,-1,sizeof(par));
    memset(val,0,sizeof(val));
}
int find(int x)
{
    if(par[x]==-1)
    {
        return x;
    }
    int tmp=find(par[x]);
    val[x]+=val[par[x]];
    return par[x]=tmp;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
bool unite(int x,int y,int sum)
{
    int xx=find(x);
    int yy=find(y);
    if(xx==yy)
    {
        if((val[y]-val[x])!=sum)
        {
            return true;
        }
        return false;
    }
    par[yy]=xx;
    val[yy]=val[x]-val[y]+sum;
    return false;
}
int main()
{
    int N,M;
    while(~scanf("%d%d",&N,&M))
    {
        init();
        int ans=0;
        for(int i=0;i<M;++i)
        {
            int x,y,sum;
            scanf("%d%d%d",&x,&y,&sum);
            --x;
            if(unite(x,y,sum))
            {
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}