#include<cstdio>
#include<stack>
#include<cstring>
#include<cmath>
#include<utility>
using namespace std;
int dp[100020][2];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        long long d,k;
        scanf("%lld%lld",&d,&k);
        int t=d/k,last=0;
        long long su=d*d;
        for(int i=t;i>=0;--i){
            long long tmp=i*k;
            tmp*=tmp;
            int j;
            for(j=last;;++j){
                long long yt=j*k;
                yt*=yt;
                if((yt+tmp)<su){
                    continue;
                }else if((yt+tmp)>su){
                    j--;
                    break;
                }else{
                    break;
                }
            }
            int tmp2=j;
            dp[j+1][i%2]=1;
            for(;j>=0;--j){
                if(j>last){
                    if(dp[j+1][i%2]){
                        dp[j][i%2]=0;
                    }else{
                        dp[j][i%2]=1;
                    }
                }else{
                    if(dp[j+1][i%2]&&dp[j][(i+1)%2]){
                        dp[j][i%2]=0;
                    }else{
                        dp[j][i%2]=1;
                    }
                }
            }
            last=tmp2;
        }
        if(dp[0][0]){
            printf("Ashish\n");
        }else{
            printf("Utkarsh\n");
        }
    }
    return 0;
}