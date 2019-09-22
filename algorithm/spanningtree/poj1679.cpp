#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=120;
struct edge
{
    int from,to,weight;
    bool operator<(const edge &rhs) const
    {
        return weight>rhs.weight;
    }
};
int par[maxn];
vector<edge> G[maxn];
int parent[maxn],depth[maxn];
int lca[10][maxn],wei[10][maxn];
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
        return par[x];
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
void dfs(int node,int paren,int d)
{
    parent[node]=paren;
    depth[node]=d;
    lca[0][node]=paren;
    for(int i=0;i<G[node].size();++i)
    {
        int to=G[node][i].to;
        if(parent[to]<0)
        {
            dfs(to,node,d+1);
            wei[0][node]=max(wei[0][node],G[node][i].weight);
        }
    }
}
void init(int root,int V)
{
    for(int k=0;k<8;++k)
    {
        for(int v=1;v<=V;++v)
        {
            if(lca[k][v]!=-1)
            {
                lca[k+1][v]=lca[k][lca[k][v]];
                wei[k+1][v]=max(wei[k][v],wei[k][lca[k][v]]);
            }
            else
            {
                lca[k+1][v]=-1;
            }
        }
    }
}
int findlca(int u,int v)
{
    int ans=0;
    if(depth[u]>depth[v])
    {
        swap(u,v);
    }
    for(int k=0;k<8;++k)
    {
        if((depth[v]-depth[u])>>k&1)
        {
            ans=max(ans,wei[k][v]);
            v=lca[k][v];
        }
    }
    if(u==v)
    {
        return ans;
    }
    for(int k=8;k>=0;--k)
    {
        if(lca[k][v]!=lca[k][u])
        {
            ans=max(ans,wei[k][v]);
            v=wei[k][v];
            ans=max(ans,wei[k][u]);
            u=wei[k][u];
        }
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        init(n);
        for(int i=0;i<=n;++i)
        {
            G[i].clear();
        }
        memset(parent,-1,sizeof(parent));
        memset(depth,-1,sizeof(depth));
        memset(lca,-1,sizeof(lca));
        memset(wei,-1,sizeof(wei));
        priority_queue<edge> que;
        vector<edge> vec;
        int mst=0;
        for(int i=0;i<m;++i)
        {
            edge tmp;
            scanf("%d%d%d",&tmp.from,&tmp.to,&tmp.weight);
            que.push(tmp);
        }
        for(int i=0;i<m;++i)
        {
            edge tmp=que.top();
            que.pop();
            if(!same(tmp.from,tmp.to))
            {
                G[tmp.from].push_back(tmp);
                swap(tmp.from,tmp.to);
                G[tmp.from].push_back(tmp);
                mst+=tmp.weight;
                unite(tmp.from,tmp.to);
            }
            else
            {
                vec.push_back(tmp);
            }
        }
        dfs(1,0,0);
        lca[0][1]=-1;
        init(1,n);
        int haveuni=1;
        for(int i=0;i<vec.size();++i)
        {
            if(vec[i].weight==findlca(vec[i].from,vec[i].to))
            {
                printf("Not Unique!\n");
                haveuni=0;
                break;
            }
        }
        if(haveuni)
        {
            printf("%d\n",mst);
        }
    }
    return 0;
}