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
    int N,F,D;
    scanf("%d%d%d",&N,&F,&D);
    int sum=N+F+D+N;
    for(int i=0;i<F;++i)
    {
        addedge(sum,i+2*N,1);
    }
    for(int i=0;i<D;++i)
    {
        addedge(i+2*N+F,sum+1,1);
    }
    for(int i=0;i<N;++i)
    {
        addedge(i*2,i*2+1,1);
    }
    for(int i=0;i<N;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        for(int j=0;j<a;++j)
        {
            int tmp;
            scanf("%d",&tmp);
            --tmp;
            addedge(tmp+N*2,i*2,1);
        }
        for(int j=0;j<b;++j)
        {
            int tmp;
            scanf("%d",&tmp);
            --tmp;
            addedge(i*2+1,tmp+N*2+F,1);
        }
    }
    int ans=maxflow(sum,sum+1);
    printf("%d\n",ans);
    return 0;
}