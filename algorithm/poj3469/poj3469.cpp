//最小割的问题···想好如何建图大概就能够理解了···但是规模很大···所以似乎应该找更快的网络流算法了···
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1e9;
struct edge
{
    int to,cap,rev;
};
vector<edge> G[20050];
int level[20050];
int iter[20050];
void add_edge(int from,int to,int cap)
{
    edge tmp;
    tmp.to=to,tmp.cap=cap,tmp.rev=G[to].size();
    G[from].push_back(tmp);
    tmp.to=from,tmp.cap=0,tmp.rev=G[from].size()-1;
    G[to].push_back(tmp);
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        for(int i=0;i<G[v].size();++i)
        {
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v,int t,int f)
{
    if(v==t)
    {
        return f;
    }
    for(int &i=iter[v];i<G[v].size();++i)
    {
        edge &e=G[v][i];
        if(e.cap>0&&level[v]<level[e.to])
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
        bfs(s);
        if(level[t]<0)
        {
            return flow;
        }
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0)
        {
            flow+=f;
        }
    }
}
int N,M;
int A[20050],B[20050];
int main()
{
    scanf("%d%d",&N,&M);
    int s=N,t=s+1;
    for(int i=0;i<N;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add_edge(i,t,a);
        add_edge(s,i,b);
    }
    for(int i=0;i<M;++i)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        add_edge(a-1,b-1,w);
        add_edge(b-1,a-1,w);
    }
    printf("%d\n",max_flow(s,t));
    return 0;
}