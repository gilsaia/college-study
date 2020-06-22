#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char matrix[1200][1200];
int dp[1200][1200];
int main(){
    int n;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;++i){
            scanf("%s",matrix[i]);
        }
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<n;++i){
            for(int j=0;(j+i)<n;++j){
                for(int t=0;(t+i)<n;++t){
                    if(dp[j][t+1]==(i-1)&&dp[j+1][t]==(i-1)&&matrix[j][t]==matrix[j+i][t+i]){
                        dp[j][t]=i;
                        ans=i;
                    }
                }
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}