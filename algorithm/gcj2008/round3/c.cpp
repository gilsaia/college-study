#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
int V;
vector<int> G[6600];
int match[6600];
bool used[6600];
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
    for(int v=0;v<V;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                ++res;
            }
        }
    }
    return res;
}
const int dx[4]={-1,-1,1,1},dy[4]={-1,0,-1,0};
int M,N;
char seat[100][100];
void solve()
{
    int num=0;
    V=M*N;
    for(int i=0;i<=V;++i)
    {
        G[i].clear();
    }
    for(int y=0;y<M;++y)
    {
        for(int x=0;x<N;++x)
        {
            if(seat[y][x]=='.')
            {
                ++num;
                for(int k=0;k<4;++k)
                {
                    int x2=x+dx[k],y2=y+dy[k];
                    if(0<=x2&&x2<N&&0<=y2&&y2<M&&seat[y2][x2]=='.')
                    {
                        add_edge(x*M+y,x2*M+y2);
                    }
                }
            }
        }
    }
    printf("%d\n",num-bipartite_matching());
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>M>>N;
        for(int t=0;t<M;++t)
        {
            for(int j=0;j<N;++j)
            {
                cin>>seat[t][j];
            }
        }
        printf("Case #%d: ",i);
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}