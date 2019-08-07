
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 3600 + 5, maxc = 60 + 5, maxr = 60 + 5, inf = 0x3f3f3f3f;
struct Node{ll x; ll y;}city[maxn];
int L[maxn], R[maxn], D[maxn], U[maxn], C[maxn];
 // 记录某个标号的节点的上下左右节点的编号
int S[maxc], H[maxr], sz;
  // H记录每行节点的信息(无行头)，S保存某一列1的数量
int n, m, k;
ll d[maxr][maxc], t[maxn];
///不需要S域
void init(int x)///col is 1~x,row start from 1
{
    for (int i = 0; i <= x; ++i)
    {
        S[i] = 0;
        D[i] = U[i] = i;
        L[i+1] = i; R[i] = i+1;
    }///对列表头初始化
    R[x] = 0;
    sz = x + 1;///真正的元素从m+1开始
    memset (H, -1, sizeof(H));
    ///mark每个位置的名字
}
void Link(int r, int c)
{
    S[c]++; C[sz] = c;
    U[sz] = U[c]; D[U[c]] = sz;
    D[sz] = c; U[c] = sz;
    U[c] = sz;
    if(H[r] == -1) H[r] = L[sz] = R[sz] = sz;
    else
    {
        L[sz] = L[H[r]]; R[L[H[r]]] = sz;
        R[sz] = H[r]; L[H[r]] = sz;
    }
    sz++;
}
void remove(int c)
{
    for(int i = D[c]; i != c; i = D[i])
        L[R[i]] = L[i], R[L[i]] = R[i];
}
void resume(int c)
{
    for (int i = U[c]; i != c; i = U[i])
        L[R[i]] = R[L[i]] = i;
}
int h()
{///用精确覆盖去估算剪枝
    int ret = 0;
    bool vis[maxc];
    memset (vis, false, sizeof(vis));
    for(int i = R[0]; i; i = R[i])
    {
        if(vis[i]) continue;
        ret++;
        vis[i] = true;
        for (int j = D[i]; j != i; j = D[j])
            for (int k = R[j]; k != j; k = R[k])
                vis[C[k]] = true;
    }
    return ret;
}
int ans;
bool Dance(int a) //具体问题具体分析, a是递归层数
{
    if(a + h() > k) return 0;  //如果 当前层数+即将要加的层数 > 说明肯定不可以
    if(!R[0]) return a <= k;  //说明出答案了
    int c = R[0];
    for (int i = R[0]; i; i = R[i])
        if(S[i] < S[c]) c = i;
    for(int i = D[c]; i != c; i = D[i])
    {
        remove(i);
        for(int j = R[i]; j != i; j = R[j])
            remove(j);
        if(Dance(a + 1)) return 1;
        // 这里必须反着恢复
        for (int j = L[i]; j != i; j = L[j])
            resume(j);
        resume(i);
    }
    return 0;
}
ll dist(int i, int j)
{
    ll d = abs(city[i].x - city[j].x) +  abs(city[i].y - city[j].y);
    return d;
}
bool judge(ll mid)
{
    init(n);
    ans = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            if(d[i][j] <= mid)
                Link(i, j);
    }
    return Dance(0);  //从0层开始
}
int main (void)
{
    int T, ca = 1;
    cin >> T;
    while(T--)
    {
        scanf("%d%d", &n, &k);
        ll maxd = 0;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            scanf("%I64d%I64d", &city[i].x, &city[i].y);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                d[i][j] = dist(i, j);
                t[cnt++] = d[i][j];
            }
        sort(t, t + cnt);
        int ncnt = unique(t, t + cnt) - t;  //去重， 二分所有可能的距离更好
        ll l = -1, r = ncnt;
        while(r - l > 1)
        {
            ll mid = (l + r) / 2;
            if(judge(t[mid])) r = mid;
            else l = mid;
        }
        printf("Case #%d: %I64d\n", ca++, t[r]);
    }
    return 0;
}