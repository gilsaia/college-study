#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int MAXV = 2005;
const int INF = 1<<30;
struct Edge{ int to, cap, rev; };
std::vector<Edge> G[MAXV];
int level[MAXV];
int iter[MAXV]; //当前弧，之前的已经没有用了

void addedge(int from, int to, int cap) {
    G[from].push_back(Edge{to, cap, G[to].size()});
    G[to].push_back(Edge{from, 0, G[from].size()-1});
}

void bfs(int s) {
    memset(level, -1, sizeof level);
    std::queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            Edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); ++i) { // 注意i是引用 实现当前弧优化
        Edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, std::min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
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
    int N,M;
    while(~scanf("%d%d",&N,&M))
    {
        for(int i=0;i<N*2;++i)
        {
            G[i].clear();
        }
        int start,end;
        scanf("%d%d",&start,&end);
        --start,--end;
        for(int i=0;i<N;++i)
        {
            int cap;
            scanf("%d",&cap);
            addedge(i*2,i*2+1,cap);
        }
        for(int i=0;i<M;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            addedge(u*2+1,v*2,INF);
            addedge(v*2+1,u*2,INF);
        }
        int res=maxflow(start*2,end*2+1);
        printf("%d\n",res);
    }
    return 0;
}