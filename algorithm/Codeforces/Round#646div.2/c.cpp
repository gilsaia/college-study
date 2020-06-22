#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<int> G[1020];
int vis[1020];
int res[1020];
int dfs(int x){
    res[x]=0;
    vis[x]=1;
    for(int i=0;i<G[x].size();++i){
        if(!vis[G[x][i]]){
            res[x]=!(res[x]^dfs(G[x][i]));
        }
    }
    return res[x];
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,x;
        scanf("%d%d",&n,&x);
        for(int i=0;i<=n;++i){
            G[i].clear();
        }
        memset(vis,0,sizeof(vis));
        memset(res,0,sizeof(res));
        for(int i=1;i<n;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans=dfs(x);
        if(ans){
            printf("Ayush\n");
        }else{
            printf("Ashish\n");
        }
    }
    return 0;
}