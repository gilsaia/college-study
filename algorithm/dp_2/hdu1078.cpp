#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[120][120],hole[120][120];
int dfs(int &k,int &n,int i,int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    for(int t=1;t<=k;++t){
        if((i+t)<n&&hole[i+t][j]>hole[i][j]){
            ans=max(ans,dfs(k,n,i+t,j));
        }
        if((i-t)>=0&&hole[i-t][j]>hole[i][j]){
            ans=max(ans,dfs(k,n,i-t,j));
        }
        if((j+t)<n&&hole[i][j+t]>hole[i][j]){
            ans=max(ans,dfs(k,n,i,j+t));
        }
        if((j-t)>=0&&hole[i][j-t]>hole[i][j]){
            ans=max(ans,dfs(k,n,i,j-t));
        }
    }
    dp[i][j]=ans+hole[i][j];
    return dp[i][j];
}
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k),n!=-1){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d",&hole[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=dfs(k,n,0,0);
        printf("%d\n",ans);
    }
    return 0;
}