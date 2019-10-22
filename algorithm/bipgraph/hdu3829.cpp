#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1000;
const int maxn=1050;
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

vector<int> animal[maxn],antianimal[maxn];
int main()
{
    int n,m,p;
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        uN=p;
        vN=p;
        memset(g,0,sizeof(g));
        for(int i=0;i<p;++i)
        {
            animal[i].clear();
            antianimal[i].clear();
        }
        for(int i=0;i<p;++i)
        {
            char op[10];
            int num1,num2;
            getchar();
            scanf("%c%d %c%d",&op[0],&num1,&op[1],&num2);
            if(op[0]=='D')
            {
                num1+=n;
            }
            if(op[1]=='D')
            {
                num2+=n;
            }
            for(int j=0;j<antianimal[num1].size();++j)
            {
                g[antianimal[num1][j]][i]=1;
                g[i][antianimal[num1][j]]=1;
            }
            for(int j=0;j<animal[num2].size();++j)
            {
                g[i][animal[num2][j]]=1;
                g[animal[num2][j]][i]=1;
            }
            animal[num1].push_back(i);
            antianimal[num2].push_back(i);
        }
        int ans=hungary();
        printf("%d\n",p-ans/2);
    }
    return 0;
}