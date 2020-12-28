#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int used[520][520];
int dp[520][520];
char mat[520][520];
int ans;
int n,m;
int dfs(int x,int y){
    if(used[x][y]){
        return dp[x][y];
    }
    if(mat[x][y]=='.'){
        dp[x][y]=0;
        used[x][y]=1;
        return 0;
    }
    int level=1;
    if((x+1)==n||(y-1)<0||(y+1)==m){
        ans+=level;
        dp[x][y]=level;
        used[x][y]=1;
        return level;
    }
    level=min(min(dfs(x+1,y-1),dfs(x+1,y)),dfs(x+1,y+1))+1;
    ans+=level;
    dp[x][y]=level;
    used[x][y]=1;
    return level;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        char tmp[520];
        for(int i=0;i<n;++i){
            scanf("%s",mat[i]);
        }
        memset(used,0,sizeof(used));
        memset(dp,-1,sizeof(dp));
        ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!used[i][j]){
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}