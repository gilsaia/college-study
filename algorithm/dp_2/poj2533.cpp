#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=0x3f3f3f3f;
int dp[1040];
int main(){
    int n;
    scanf("%d",&n);
    memset(dp,MAXN,sizeof(dp));
    int ans=0;
    for(int i=0;i<n;++i){
        int tmp;
        scanf("%d",&tmp);
        int ide=lower_bound(dp,dp+n,tmp)-dp;
        dp[ide]=tmp;
        ans=max(ans,ide);
    }
    printf("%d\n",ans+1);
    return 0;
}