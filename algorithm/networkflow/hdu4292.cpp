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
    while(~scanf("%d%d%d",&N,&F,&D))
    {
        for(int i=0;i<(N*2+F+D+2);++i)
        {
            G[i].clear();
        }
        int start=N*2+F+D,end=start+1;
        for(int i=0;i<F;++i)
        {
            int tmp;
            scanf("%d",&tmp);
            addedge(start,N*2+i,tmp);
        }
        for(int i=0;i<D;++i)
        {
            int tmp;
            scanf("%d",&tmp);
            addedge(N*2+F+i,end,tmp);
        }
        char sta[220];
        for(int i=0;i<N;++i)
        {
            scanf("%s",sta);
            for(int j=0;j<F;++j)
            {
                if(sta[j]=='Y')
                {
                    addedge(N*2+j,i*2,1);
                }
            }
            addedge(i*2,i*2+1,1);
        }
        for(int i=0;i<N;++i)
        {
            scanf("%s",sta);
            for(int j=0;j<D;++j)
            {
                if(sta[j]=='Y')
                {
                    addedge(i*2+1,N*2+F+j,1);
                }
            }
        }
        int ans=maxflow(start,end);
        printf("%d\n",ans);
    }
    return 0;
}