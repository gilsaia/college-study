#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[100020][12],pie[100020][12];
int main(){
    int n;
    while(scanf("%d",&n),n){
        memset(dp,-1,sizeof(dp));
        memset(pie,0,sizeof(pie));
        dp[0][5]=0;
        int mtime=0;
        for(int i=0;i<n;++i){
            int p,t;
            scanf("%d%d",&p,&t);
            mtime=max(mtime,t);
            ++pie[t][p];
        }
        for(int i=1;i<=mtime;++i){
            if(dp[i-1][0]!=-1){
                dp[i][0]=max(dp[i][0],dp[i-1][0]+pie[i][0]);
            }
            if(dp[i-1][1]!=-1){
                dp[i][0]=max(dp[i][0],dp[i-1][1]+pie[i][0]);
            }
            for(int j=1;j<11;++j){
                for(int t=-1;t<2;++t){
                    if(dp[i-1][j+t]!=-1){
                        dp[i][j]=max(dp[i][j],dp[i-1][j+t]+pie[i][j]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<11;++i){
            ans=max(ans,dp[mtime][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}