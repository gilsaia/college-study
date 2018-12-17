#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MOD=1e9+9;
int dp[2][10];
int main()
{
    int T;
    scanf("%d",&T);
    for(int m=0;m<T;++m)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<9;++i)
        {
            dp[0][i]=dp[1][i]=0;
        }
        for(int i=0;i<n;++i)
        {
            int side;
            scanf("%d",&side);
            side%=9;
            side=side*side*side;
            side=side%9;
            for(int j=0;j<9;++j)
            {
                dp[i%2][j]=dp[(i+1)%2][j];
            }
            dp[i%2][side]++;
            for(int j=0;j<9;++j)
            {
                dp[i%2][(j+side)%9]+=dp[(i+1)%2][j];
                dp[i%2][(j+side)%9]%=MOD;
            }
        }
        printf("%d\n",dp[(n-1)%2][0]);
    }
    return 0;
}