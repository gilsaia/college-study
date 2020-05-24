#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1020],chess[1020];
int main(){
    int n;
    while(scanf("%d",&n),n){
        memset(dp,0,sizeof(dp));
        memset(chess,0,sizeof(chess));
        for(int i=0;i<n;++i){
            scanf("%d",&chess[i]);
            dp[i]=chess[i];
            for(int j=0;j<i;++j){
                if(chess[j]<chess[i]){
                    dp[i]=max(dp[i],dp[j]+chess[i]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;++i){
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}