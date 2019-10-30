#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[2040][2040],dat[2040];
int main()
{
    int n;
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;++i)
    {
        scanf("%d",&dat[i]);
        dp[i][i]=n*dat[i];
    }
    for(int len=1;len<n;++len)
    {
        for(int i=0;i<n;++i)
        {
            if((i+len)<n)
            {
                dp[i][i+len]=max(dp[i][i+len],dp[i+1][i+len]+(n-len)*dat[i]);
                dp[i][i+len]=max(dp[i][i+len],dp[i][i+len-1]+(n-len)*dat[i+len]);
            }
        }
    }
    printf("%d\n",dp[0][n-1]);
    return 0;
}