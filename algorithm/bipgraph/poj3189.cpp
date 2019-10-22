#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1020;
const int B = 30;
int n, b;
int Rank[N][B], vlink[B], link[B][N], cap[B];
bool vis[B];

void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= b; j++)
            scanf("%d", &Rank[i][j]);
    for (int i = 1; i <= b; i++)
        scanf("%d", &cap[i]);
}

bool dfs(int u, int l, int r) {
    for (int i = l; i <= r; i++) {
        int v = Rank[u][i];
        if (vis[v]) continue;
        vis[v] = true;
        if (vlink[v] < cap[v]) {
            link[v][vlink[v]++] = u;
            return true;
        }

        for (int i = 0; i < cap[v]; i++) {
            if (dfs(link[v][i], l, r)) {
                link[v][i] = u;
                return true;
            }
        }
    }
    return false;
}

bool judge(int l, int r) {
    int ans = 0;
    memset(vlink, 0, sizeof(vlink));
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i, l, r)) ans++;
    }
    return ans == n;
}

bool can(int mid) {
    for (int i = 1; i + mid - 1 <= b; i++) 
        if (judge(i, i + mid - 1)) return true;
    return false;
}

void solve() {
    int l = 0, r = b, mid, ans;

    while (l <= r) {
        mid = (l + r) / 2;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    printf("%d\n", ans);
}

int main() {
    scanf("%d%d", &n, &b);
    init();
    solve();
    return 0;
}