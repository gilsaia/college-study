#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1020;
struct edge
{
    int from,to;
    double weight;
    bool operator<(const edge &rhs) const
    {
        return weight>rhs.weight;
    }
};
int par[maxn];
vector<edge> G[maxn];
int parent[maxn],depth[maxn];
int lca[15][maxn];
double wei[15][maxn];
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
        if(parent[to]==-1)
        {
            wei[0][to]=max(wei[0][to],G[node][i].weight);
            dfs(to,node,d+1);
        }
    }
}
void init(int root,int V)
{
    for(int k=0;k<12;++k)
    {
        for(int v=0;v<V;++v)
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
double findlca(int u,int v)
{
    double ans=0;
    if(depth[u]>depth[v])
    {
        swap(u,v);
    }
    for(int k=0;k<12;++k)
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
    for(int k=12;k>=0;--k)
    {
        if(lca[k][v]!=lca[k][u])
        {
            ans=max(ans,wei[k][v]);
            v=lca[k][v];
            ans=max(ans,wei[k][u]);
            u=lca[k][u];
        }
    }
    ans=max(wei[0][u],ans);
    ans=max(wei[0][v],ans);
    return ans;
}
struct point
{
    int x,y,num;
};
int lengt(point x,point y)
{
    return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}
point city[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        init(n);
        for(int i=0;i<=n;++i)
        {
            G[i].clear();
        }
        memset(parent,-1,sizeof(parent));
        memset(depth,-1,sizeof(depth));
        memset(lca,-1,sizeof(lca));
        memset(wei,0,sizeof(wei));
        priority_queue<edge> que;
        vector<edge> vec,vec_2;
        double mst=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d",&city[i].x,&city[i].y,&city[i].num);
            for(int j=0;j<i;++j)
            {
                double leng=sqrt(lengt(city[i],city[j]));
                edge tmp;
                tmp.from=j,tmp.to=i,tmp.weight=leng;
                que.push(tmp);
            }
        }
        while(!que.empty())
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
                vec_2.push_back(tmp);
            }
            else
            {
                vec.push_back(tmp);
            }
        }
        dfs(0,-2,0);
        lca[0][0]=-1;
        init(0,n);
        double ans=0;
        for(int i=0;i<vec_2.size();++i)
        {
            double people=city[vec_2[i].from].num+city[vec_2[i].to].num;
            double lengt=mst-vec_2[i].weight;
            ans=max(ans,people/lengt);
        }
        for(int i=0;i<vec.size();++i)
        {
            double people=city[vec[i].from].num+city[vec[i].to].num;
            double lengt=mst-findlca(vec[i].from,vec[i].to);
            ans=max(ans,people/lengt);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}