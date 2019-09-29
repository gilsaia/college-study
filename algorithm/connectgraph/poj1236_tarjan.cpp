#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int V=1.5e3;
const int E=1.5e4;

struct edge
{
    int from,to, next;
}Edge[E];
int head[V], e;
int belong[V], low[V], dfn[V], scc, cnt;//dfn[]:遍历到u点的时间; low[]:u点可到达的各点中最小的dfn[v]
int S[V], top;
bool vis[V];//v是否在栈中
void init()
{
    memset(head,-1,sizeof(head));
    e=0;
}
int addedge(int u, int v)
{
    Edge[e].from=u;
    Edge[e].to = v;
    Edge[e].next = head[u];
    head[u] = e++;
    return 0;
}
void tarjan(int u)
{
    int v;
    dfn[u] = low[u] = ++cnt;//开始时dfn[u] == low[u]
    S[top++] = u;//不管三七二十一进栈
    vis[u] = true;
    for (int i=head[u]; i!=-1; i=Edge[i].next)
    {
        v = Edge[i].to;
        if (dfn[v] == 0)//如果v点还未遍历
        {
            tarjan(v);//向下遍历
            low[u] = low[u] < low[v] ? low[u] : low[v];//确保low[u]最小
        }
        else if (vis[v] && low[u] > dfn[v])//v在栈中，修改low[u]
            low[u] = dfn[v];
    }
    if (dfn[u] == low[u])//u为该强连通分量中遍历所成树的根
    {
        ++scc;
        do
        {
            v = S[--top];//栈中所有到u的点都属于该强连通分量，退栈
            vis[v] = false;
            belong[v] = scc;
        } while (u != v);
    }

}

int solve(int n)
{
    scc = top = cnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(vis, false, sizeof(vis));
    for (int u=1; u<=n; ++u)
        if (dfn[u] == 0)
            tarjan(u);
    return scc;
}
int out[V],in[V];
int main()
{
    int n;
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;++i)
    {
        int u;
        while(scanf("%d",&u),u)
        {
            addedge(i,u);
        }
    }
    int m=solve(n);
    if(m==1)
    {
        printf("1\n0\n");
        return 0;
    }
    for(int i=0;i<e;++i)
    {
        if(belong[Edge[i].from]!=belong[Edge[i].to])
        {
            ++out[belong[Edge[i].from]];
            ++in[belong[Edge[i].to]];
        }
    }
    int ansin=0,ansout=0;
    for(int i=1;i<=m;++i)
    {
        if(in[i]==0)
        {
            ++ansin;
        }
        if(out[i]==0)
        {
            ++ansout;
        }
    }
    printf("%d\n%d\n",ansin,max(ansin,ansout));
    return 0;
}