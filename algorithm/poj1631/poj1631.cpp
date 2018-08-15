//简单的求一个最长上升子序列的问题，按方法直接套就好··
#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[40020],dat[40020];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&dat[i]);
        }
        fill(dp,dp+n,100000);
        for(int i=0;i<n;i++)
        {
            *lower_bound(dp,dp+n,dat[i])=dat[i];
        }
        printf("%d\n",lower_bound(dp,dp+n,100000)-dp);
    }
    return 0;
}