//二分匹配的题···把连续的横木板的坐标和纵木板的坐标当做节点连边然后找最小定点覆盖即求最大匹配即可
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int V;
vector<int> G[5500];
int match[5500];
bool used[5500];
bool toprint[550][550];
int posx[550],posy[550];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();++i)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<V;++v)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    int R,C;
    scanf("%d%d",&R,&C);
    V=R*C;
    int xpos=1,ypos=1;
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;++j)
        {
            char tmp;
            cin>>tmp;
            if(tmp=='*')
            {
                toprint[i][j]=1;
                posx[i]=xpos;
                int x = i,y = j;
                while(x > 0 && toprint[x-1][j] == 1) x--;
                while(y > 0 && toprint[i][y-1] == 1) y--;
                add_edge(x*C+j,i*C+y+R*C);
            }
        }
    }
    printf("%d\n",bipartite_matching());
    return 0;
}