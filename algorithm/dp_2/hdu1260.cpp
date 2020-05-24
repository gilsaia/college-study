#include<cstdio>
#include<algorithm>
using namespace std;
int dp[2020],adi[2020],si[2020];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int k;
        scanf("%d",&k);
        for(int i=1;i<=k;++i){
            scanf("%d",&si[i]);
        }
        for(int i=2;i<=k;++i){
            scanf("%d",&adi[i]);
        }
        dp[0]=0;
        dp[1]=si[1];
        for(int i=2;i<=k;++i){
            dp[i]=min(dp[i-1]+si[i],dp[i-2]+adi[i]);
        }
        int s=dp[k]%60,m=(dp[k]/60)%60,h=(dp[k]/3600+8)%24;
        int af=0;
        if(h>12){
            af=1;
            h-=12;
        }
        printf("%02d:%02d:%02d %s\n",h,m,s,af?"pm":"am");
    }
    return 0;
}