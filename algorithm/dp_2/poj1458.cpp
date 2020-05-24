#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1200][1200];
char x[1200],y[1200];
int main(){
    while(~scanf("%s%s",x,y)){
        memset(dp,0,sizeof(dp));
        int i,j;
        for(i=0;x[i]!='\0';++i){
            for(j=0;y[j]!='\0';++j){
                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                if(x[i]==y[j]){
                    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
                }
            }
        }
        printf("%d\n",dp[i][j]);
    }
    return 0;
}