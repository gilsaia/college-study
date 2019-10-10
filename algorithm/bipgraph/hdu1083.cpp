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
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&uN,&m);
        for(int i=0;i<uN;++i)
        {
            int count;
            scanf("%d",&count);
            G[i].clear();
            for(int j=0;j<count;++j)
            {
                int tmp;
                scanf("%d",&tmp);
                G[i].push_back(tmp);
            }
        }
        int ans=hungary();
        if(ans==uN)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}