#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxn 1100
#define INF 0x3f3f3f3f
 
int dfn[maxn], low[maxn], head[maxn], f[maxn];
int n, m;
int minn, tol, cnt;
struct Edge
{
    int u, v, w;
    int next;
} edge[maxn*maxn];
void init()
{
    cnt = tol = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(f, 0, sizeof(f));
}
 
void addEdge(int u, int v, int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol].w = w;
    edge[tol].next = head[u];
    head[u] = tol++;
}
 
void Tarjan(int u, int fa)
{
    int i, v, flag = 0;
    low[u] = dfn[u] = ++cnt;
    f[u] = fa;
    for(i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if(v == fa && !flag)//去重
        {
            flag = 1;
            continue;
        }
        if(!dfn[v])
        {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(dfn[u] < low[v])
                minn = min(minn, edge[i].w);
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
}
 
int main()
{
    int u, v, w;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        init();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        minn = INF;
        int k = 0;
        for(int i = 1 ; i <= n; i++)
        {
            if(!dfn[i])
            {
                Tarjan(i, -1);
                k++;
            }
        }
        if(k > 1)//不连通
        {
            printf("0\n");
            continue;
        }
        if(minn == 0)//最少0守卫
            printf("1\n");
        else if(minn == INF)//无解
            printf("-1\n");
        else
            printf("%d\n", minn);
    }
    return 0;
}