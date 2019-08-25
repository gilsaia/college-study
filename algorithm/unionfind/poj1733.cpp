#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=10200;
int par[MAXN],val[MAXN];
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
    int tmp=par[x];
    par[x]=find(par[x]);
    val[x]^=val[tmp];
    return par[x];
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void unite(int x,int y,int num)
{
    int tx=find(x);
    int ty=find(y);
    if(tx==ty)
    {
        return;
    }
    par[tx]=ty;
    val[tx]=val[x]^val[y]^num;
}
map<int,int> reflec;
int con[MAXN][3];
int has[MAXN];
int main()
{
    int len;
    scanf("%d",&len);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        char op[20];
        scanf("%d %d %s",&con[i][0],&con[i][1],op);
        --con[i][0];
        has[i*2]=con[i][0],has[i*2+1]=con[i][1];
        if(op[0]=='o')
        {
            con[i][2]=1;
        }
        else
        {
            con[i][2]=0;
        }
    }
    sort(has,has+n*2);
    int m=unique(has,has+n*2)-has;
    for(int i=0;i<m;++i)
    {
        reflec[has[i]]=i;
    }
    init(m);
    int ans=0,wrong=0;
    for(int i=0;i<n;++i)
    {
        int x=reflec[con[i][0]],y=reflec[con[i][1]];
        if(same(x,y))
        {
            if((val[x]^val[y])!=con[i][2])
            {
                wrong=1;
                break;
            }
        }
        else
        {
            unite(x,y,con[i][2]);
        }
        ++ans;
    }
    printf("%d\n",ans);
    return 0;
}