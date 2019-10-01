#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 11000;
struct node
{
    int to, next;
} edge[maxn*10];
bool cmp (node a, node b)
{
    if (a.next == b.next)
        return a.to < b.to;
    return a.next < b.next;
}
int low[maxn], dfn[maxn], head[maxn];
int Father[maxn], tot, ntime, cnt;
node Q[maxn * 10];
void init ()
{
    ntime = tot = cnt = 0;
    memset (low, 0, sizeof(low));
    memset (dfn, 0, sizeof(dfn));
    memset (head, -1, sizeof(head));
    memset (Father, 0, sizeof(Father));
}
void Add (int from, int to)
{
    edge[tot].to = to;
    edge[tot].next = head[from];
    head[from] = tot ++;
}
void Tarjan (int u, int father)
{
    low[u] = dfn[u] = ++ntime;
    Father[u] = father;
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            Tarjan (v, u);
            low[u] = min (low[u], low[v]);
        }
       else if (father != v)
            low[u] = min (low[u], dfn[v]);
    }
}
int main ()
{
    int n, m;
    node q;
    while (scanf ("%d", &n) != EOF)
    {
        init ();
        m = n;
        while (n --)
        {
            int u , k;
            scanf ("%d (%d)", &u, &k);
            while (k --)
            {
                int v;
                scanf ("%d", &v);
                Add (u, v);
                Add (v, u);
            }
        }
        for (int i=0; i<m; i++)
            if (!dfn[i])
                Tarjan (i, -1);
        
        for (int i=0; i<m; i++)
        {
            int v = Father[i];
            if (v != -1 && dfn[v] < low[i])
            {
                q.next = v;
                q.to = i;
                if (q.next > q.to)
                    swap(q.next, q.to);
                Q[cnt++] = q;
            }
        }
        printf ("%d critical links\n", cnt);
        sort (Q, Q+cnt, cmp);
        for (int i=0; i<cnt; i++)
            printf ("%d - %d\n", Q[i].next, Q[i].to);
        printf ("\n");
    }
    return 0;
}