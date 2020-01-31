#include <cstdio>
#include <vector>
#include <cstring>
#include<algorithm>
#include <queue>
using namespace std;
const int MAXV = 1050;
const int maxm=10050;
const int INF = 1<<30;
int edge;
int level[MAXV];
int iter[MAXV]; //当前弧，之前的已经没有用了
int head[MAXV];
struct edgenode
{
    int from;
    int to;//边的指向
    int cap;//边的容量
    int next;//链表的下一条边
} edges[maxm];
void init()
{
    edge=0;
    memset(head,-1,sizeof(head));
}
void addedge(int from, int to, int cap) {
    edges[edge].from=from;
    edges[edge].cap=cap;
    edges[edge].to=to;
    edges[edge].next=head[from];
    head[from]=edge++;
    edges[edge].from=to;
    edges[edge].cap=0;
    edges[edge].to=from;
    edges[edge].next=head[to];
    head[to]=edge++;
}

void bfs(int s) {
    memset(level, -1, sizeof level);
    std::queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = head[v]; i !=-1; i=edges[i].next) {
            edgenode &e = edges[i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    if(iter[v]==0)
    {
        iter[v]=head[v];
    }
    for (int &i = iter[v]; i !=-1; i=edges[i].next) { // 注意i是引用 实现当前弧优化
        edgenode &e = edges[i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, std::min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                edges[i^1].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    for (; ;) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof iter);
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
    return flow;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m),n+m)
    {
        init();
        for(int i=0;i<m;++i)
        {
            int u,v,cap;
            scanf("%d%d%d",&u,&v,&cap);
            addedge(u,v,cap);
            addedge(v,u,cap);
        }
        int res=maxflow(1,2);
        for(int i=0;i<edge;i+=2)
        {
            if(level[edges[i].from]!=-1&&level[edges[i].to]==-1)
            {
                printf("%d %d\n",edges[i].from,edges[i].to);
            }
        }
        printf("\n");
    }
    return 0;
}