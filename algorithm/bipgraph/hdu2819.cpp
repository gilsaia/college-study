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
int swused[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
        {
            G[i].clear();
            for(int j=0;j<n;++j)
            {
                int tmp;
                scanf("%d",&tmp);
                if(tmp==1)
                {
                    G[i].push_back(j);
                }
            }
        }
        uN=n;
        vector<int> swa,swb;
        int ans=0;
        if(hungary()==n)
        {
            memset(swused,0,sizeof(swused));
            for(int i=0;i<n;++i)
            {
                if(link[i]!=i&&!swused[i])
                {
                    swa.push_back(i+1);
                    swb.push_back(link[i]+1);
                    ++ans;
                    swused[i]=true;
                    for(int j=0;j<n;++j)
                    {
                        if(link[j]==i)
                        {
                            if(j==link[i])
                            {
                                swused[link[i]]=true;
                            }
                            else
                            {
                                link[j]=link[i];
                            }
                        }
                    }
                }
            }
            printf("%d\n",ans);
            for(int i=0;i<ans;++i)
            {
                printf("R %d %d\n",swa[i],swb[i]);
            }
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}