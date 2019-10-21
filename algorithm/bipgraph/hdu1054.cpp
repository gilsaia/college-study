#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1565; //这个值要超过两边个数的较大者，因为有link
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
    int n;
    while(~scanf("%d",&n))
    {
        uN=n;
        for(int i=0;i<n;++i)
        {
            G[i].clear();
        }
        for(int i=0;i<n;++i)
        {
            int num;
            scanf("%d",&num);
            char tmp=getchar();
            if(tmp==':')
            {
                int k;
                scanf("(%d)",&k);
                for(int j=0;j<k;++j)
                {
                    int t;
                    scanf("%d",&t);
                    G[num].push_back(t);
                    G[t].push_back(num);
                }
            }
        }
        int ans=hungary();
        printf("%d\n",ans/2);
    }
    return 0;
}