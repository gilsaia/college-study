#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[30030];
const int MAXN=0x3f3f3f3f;
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(dp,MAXN,sizeof(dp));
        int res=0,last=0,tmp;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            int j=0;
            while(dp[j]<tmp){
                ++j;
            }
            dp[j]=tmp;
        }
        for(res=0;res<n;++res){
            if(dp[res]!=MAXN){
                continue;
            }
            break;
        }
        printf("%d\n",res);
    }
    return 0;
}