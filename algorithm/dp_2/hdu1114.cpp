#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=0x3f3f3f3f;
int dp[20020];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp,maxn,sizeof(dp));
        int before,after;
        scanf("%d%d",&before,&after);
        int upsum=after-before;
        dp[0]=0;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            int v,w;
            scanf("%d%d",&v,&w);
            for(int j=0;j<upsum;++j){
                if(dp[j]!=maxn){
                    dp[j+w]=min(dp[j+w],dp[j]+v);
                }
            }
        }
        if(dp[upsum]!=maxn){
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[upsum]);
        }else{
            printf("This is impossible.\n");
        }
    }
    return 0;
}