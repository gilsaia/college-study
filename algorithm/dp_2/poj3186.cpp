#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long dp[2040][2040];
int treat[2020];
int main(){
    int n;
    scanf("%d",&n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &treat[i]), dp[i][i] = treat[i]*n;
    for(int len = 1; len < n; len++){
        for(int i = 1; i < n; i++){
            int j = i + len;
            dp[i][j] = max(dp[i+1][j]+treat[i]*(n-len), dp[i][j-1]+treat[j]*(n-len)); 
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}