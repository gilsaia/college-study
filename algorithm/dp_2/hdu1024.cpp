#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1000030],number[1000030],maxm[1000030];
const int INF=0x3fffffff;
int main(){
    int m,n;
    while(~scanf("%d%d",&m,&n)){
        memset(dp,0,sizeof(dp));
        memset(maxm,0,sizeof(maxm));
        for(int i=1;i<=n;++i){
            scanf("%d",&number[i]);
        }
        int lastmaxm=-INF;
        for(int i=1;i<=m;++i){
            lastmaxm=-INF;
            for(int j=i;j<=n;++j){
                dp[j]=max(dp[j-1]+number[j],maxm[j-1]+number[j]);
                maxm[j-1]=lastmaxm;
                lastmaxm=max(lastmaxm,dp[j]);
            }
        }
        printf("%d\n",lastmaxm);
    }
    return 0;
}