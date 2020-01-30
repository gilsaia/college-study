#include <cstdio>
#include <vector>
#include <cstring>
#include<algorithm>
#include <queue>
using namespace std;
const int MAXV = 100050;
const int maxm=100050;
const int INF = 1<<30;
int edge;
// struct Edge{ int to, cap, rev; };
// std::vector<Edge> G[MAXV];
int level[MAXV];
int iter[MAXV]; //当前弧，之前的已经没有用了
int head[MAXV];
struct edgenode
{
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
    edges[edge].cap=cap;
    edges[edge].to=to;
    edges[edge].next=head[from];
    head[from]=edge++;
    edges[edge].cap=0;
    edges[edge].to=from;
    edges[edge].next=head[to];
    head[to]=edge++;
    // G[from].push_back(Edge{to, cap, G[to].size()});
    // G[to].push_back(Edge{from, 0, G[from].size()-1});
}

void bfs(int s) {
    memset(level, -1, sizeof level);
    std::queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        // for (int i = 0; i < G[v].size(); ++i) {
        //     Edge &e = G[v][i];
        //     if (e.cap > 0 && level[e.to] < 0) {
        //         level[e.to] = level[v] + 1;
        //         que.push(e.to);
        //     }
        // }
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
    // for (int &i = iter[v]; i < G[v].size(); ++i) { // 注意i是引用 实现当前弧优化
    //     Edge &e = G[v][i];
    //     if (e.cap > 0 && level[v] < level[e.to]) {
    //         int d = dfs(e.to, t, std::min(f, e.cap));
    //         if (d > 0) {
    //             e.cap -= d;
    //             G[e.to][e.rev].cap += d;
    //             return d;
    //         }
    //     }
    // }
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
struct island
{
    int x,pos;
};
bool cmp(island a,island b)
{
    return a.x<b.x;
}
island lands[100030];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M;
        scanf("%d%d",&N,&M);
        // for(int i=0;i<=N;++i)
        // {
        //     G[i].clear();
        // }
        init();
        for(int i=0;i<N;++i)
        {
            int x,y;
            scanf("%d%d",&lands[i].x,&y);
            lands[i].pos=i+1;
        }
        sort(lands,lands+N,cmp);
        for(int i=0;i<M;++i)
        {
            int u,v,t;
            scanf("%d%d%d",&u,&v,&t);
            addedge(u,v,t);
            addedge(v,u,t);
        }
        int res=maxflow(lands[0].pos,lands[N-1].pos);
        printf("%d\n",res);
    }
    return 0;
}