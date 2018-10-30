//任意两点最短路+最大流+二分查找···
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int d[250][250];
int V,K,C,M;
const int INF=1e5;
void warshall_floyd()
{
    for(int k=1;k<=V;++k)
    {
        for(int i=1;i<=V;++i)
        {
            for(int j=1;j<=V;++j)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
struct edge
{
    int to,cap,rev;
};
vector<edge> G[250];
bool used[250];
void add_edge(int from,int to,int cap)
{
    edge temp1,temp2;
    temp1.to=to,temp1.cap=cap,temp1.rev=G[to].size();
    G[from].push_back(temp1);
    temp2.to=from,temp2.cap=0,temp2.rev=G[from].size()-1;
    G[to].push_back(temp2);
}
int dfs(int v,int t,int f)
{
    if(v==t)
    {
        return f;
    }
    used[v]=true;
    for(int i=0;i<G[v].size();++i)
    {
        edge &e=G[v][i];
        if(!used[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        memset(used,0,sizeof(used));
        int f=dfs(s,t,INF);
        if(f==0)
        {
            return flow;
        }
        flow+=f;
    }
}
void build(int dis)
{
    for(int i=0;i<=V+1;++i)
    {
        G[i].clear();
    }
    for(int i=1;i<=K;++i)
    {
        add_edge(0,i,M);
        for(int j=K+1;j<=V;++j)
        {
            if(d[i][j]<=dis)
            {
                add_edge(i,j,1);
            }
        }
    }
    for(int j=K+1;j<=V;++j)
    {
        add_edge(j,V+1,1);
    }
}
int main()
{
    scanf("%d%d%d",&K,&C,&M);
    V=K+C;
    for(int i=1;i<=V;++i)
    {
        for(int j=1;j<=V;++j)
        {
            int temp;
            scanf("%d",&temp);
            if(i==j)
            {
                d[i][j]=0;
            }
            else if(temp!=0)
            {
                d[i][j]=temp;
            }
            else
            {
                d[i][j]=INF;
            }
        }
    }
    warshall_floyd();
    int l=0,r=INF;
    while(r>=l)
    {
        int mid=(l+r)/2;
        build(mid);
        if(max_flow(0,V+1)==C)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    printf("%d\n",l);
    return 0;
}