#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000;
int uN,vN;  //u,v数目
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    int v;
    for(v=0;v<vN;v++)
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }    
        }  
    return false;  
}    
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u))  res++;
    } 
    return res;   
}  
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m),n+m)
    {
        uN=n,vN=n;
        memset(g,0,sizeof(g));
        for(int i=0;i<m;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[--u][--v]=1;
        }
        for(int k=0;k<n;++k)
        {
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {
                    g[i][j]|=(g[i][k]&g[k][j]);
                }
            }
        }
        int ans=hungary();
        printf("%d\n",n-ans);
    }
    return 0;
}