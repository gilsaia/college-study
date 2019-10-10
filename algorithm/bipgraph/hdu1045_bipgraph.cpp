#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1505; //这个值要超过两边个数的较大者，因为有link
int link[maxn];
bool used[maxn];
vector<int> G[maxn];
int uN;
bool dfs(int u)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        if (!used[G[u][i]])
        {
            used[G[u][i]] = true;
            if (link[G[u][i]] == -1 || dfs(link[G[u][i]]))
            {
                link[G[u][i]] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int u;
    int res = 0;
    memset(link, -1, sizeof(link));
    for (u = 0; u < uN; u++)
    {
        memset(used, false, sizeof(used));
        if (dfs(u))
            res++;
    }
    return res;
}
char maps[10][10];
int belong[10][10][2];
int main()
{
    int n;
    while (~scanf("%d", &n), n)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", maps[i]);
        }
        memset(belong, -1, sizeof(belong));
        uN = 0;
        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (maps[i][j] == '.')
                {
                    belong[i][j][0] = num;
                }
                else
                {
                    ++num;
                }
            }
            ++num;
        }
        G[0].clear();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (maps[j][i] == '.')
                {
                    belong[j][i][1] = uN;
                    G[uN].push_back(belong[j][i][0]);
                }
                else
                {
                    ++uN;
                    G[uN].clear();
                }
            }
            ++uN;
            G[uN].clear();
        }
        int ans = hungary();
        printf("%d\n", ans);
    }
    return 0;
}