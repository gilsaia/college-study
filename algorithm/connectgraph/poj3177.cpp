#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=5020;
int par[maxn];
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
    x=find(x),y=find(y);
    par[x]=y;
    return;
}
vector<int> son[maxn],G[maxn];
int dfn[maxn],check[maxn];
void dfs(int x,int &num,int parent)
{
    dfn[x]=num++;
    for(int i=0;i<G[x].size();++i)
    {
        int to=G[x][i];
        if(dfn[to]!=-1)
        {
            if(to!=parent&&dfn[to]<dfn[x])
            {
                check[to]-=1;
                check[x]+=1;
            }
        }
        else
        {
            son[x].push_back(to);
            dfs(to,num,x);
        }
    }
}
struct edge
{
    int from,to;
};
vector<edge> countdegree;
int degree[maxn];
int count(int x,int parent)
{
    int sum=check[x];
    for(int i=0;i<son[x].size();++i)
    {
        sum+=count(son[x][i],x);
    }
    if(sum==0)
    {
        edge tmp;
        tmp.from=x,tmp.to=parent;
        countdegree.push_back(tmp);
    }
    else
    {
        unite(x,parent);
    }
    return sum;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(dfn,-1,sizeof(dfn));
    init(n);
    for(int i=0;i<m;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int num=0;
    dfs(1,num,-1);
    for(int i=0;i<son[1].size();++i)
    {
        count(son[1][i],1);
    }
    for(int i=0;i<countdegree.size();++i)
    {
        ++degree[find(countdegree[i].from)],++degree[find(countdegree[i].to)];
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(degree[i]==1)
        {
            ++ans;
        }
    }
    ans=(ans+1)/2;
    printf("%d\n",ans);
    return 0;
}