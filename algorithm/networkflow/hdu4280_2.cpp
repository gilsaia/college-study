#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
#define N 100010
typedef long long LL;
struct Edge {
    int u, v;
    LL cap;
    Edge () {}
    Edge (int u, int v, LL cap) : u(u), v(v), cap(cap) {}
}edge[N*4];
vector<int> G[N];
int dis[N], cur[N], num[N], pre[N], tot, S, T;

void Add(int u, int v, int cap) {
    edge[tot] = Edge(u, v, cap);
    G[u].push_back(tot++);
    edge[tot] = Edge(v, u, cap);
    G[v].push_back(tot++);
}

int BFS() { // 逆向BFS
    memset(dis, -1, sizeof(dis));
    queue<int> que; que.push(T);
    dis[T] = 0;
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(int i = 0; i < G[u].size(); i++) {
            Edge &e = edge[G[u][i]];
            if(dis[e.v] == -1) {
                dis[e.v] = dis[u] + 1;
                que.push(e.v);
            }
        }
    }
    return ~dis[S];
}

int DFS() { // 通过pre数组回溯更新流量
    int u = T; int flow = INF;
    while(u != S) {
        Edge &e = edge[pre[u]];
        if(e.cap < flow) flow = e.cap;
        u = e.u;
    } u = T;
    while(u != S) {
        Edge& e1 = edge[pre[u]];
        Edge& e2 = edge[pre[u]^1];
        e1.cap -= flow; e2.cap += flow;
        u = e1.u;
    }
    return flow;
}

int ISAP(int n) {
    if(!BFS()) return 0; // 从汇点到源点逆向BFS初始化dis数组
    memset(num, 0, sizeof(num));
    memset(cur, 0, sizeof(cur)); // 当前弧优化
    for(int i = 1; i <= n; i++)
        if(~dis[i]) num[dis[i]]++; // 当前距离为dis[i]的结点数
    int ans = 0, u = S;
    while(dis[S] < n) {
        if(u == T) ans += DFS(), u = S; //  回溯之前的结点并把更新流量
        int flag = 0;
        for(int i = 0; i < G[u].size(); i++) {
            Edge &e = edge[G[u][i]];
            if(dis[e.v] + 1 == dis[u] && e.cap > 0) { // 可以增广
                pre[e.v] = G[u][i]; cur[u] = i;
                flag = 1; u = e.v;
                break;
            }
        }
        if(!flag) { // 不能增广,retreat
            if(--num[dis[u]] == 0) break; // gap优化
            int md = n;
            for(int i = 0; i < G[u].size(); i++) {
                Edge &e = edge[G[u][i]];
                if(e.cap > 0 && dis[e.v] < md) {
                    md = dis[e.v]; cur[u] = i;
                }
            }
            num[dis[u] = md + 1]++;
            if(u != S) u = edge[pre[u]].u;
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        tot = 0; for(int i = 0; i <= n; i++) G[i].clear();
        int u, v, c, west = 100000000, east = -10000000;
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &u, &v);
            if(west > u) west = u, S = i;
            if(east < u) east = u, T = i;
        }
        for(int i = 1; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &c);
            Add(u, v, c); // 无向图的话反向边的cap也是c
        }
        printf("%d\n", ISAP(n));
    }
    return 0;
}