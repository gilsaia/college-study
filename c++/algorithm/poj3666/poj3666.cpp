#include<stdio.h>
#include<algorithm>
using namespace std;
int n,cnt;
int dp[2040][2040];
const int inf=1<<30;
int arr[2040],has[2040],pre[2040];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        has[i]=arr[i];
    }
    cnt=n;
    sort(has,has+cnt);
    cnt=unique(has,has+cnt)-has;
    dp[0][0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            dp[i][j]=pre[j]+abs(has[j]-arr[i]);
            if(!j)
            {
                pre[j]=dp[i][j];
            }
            else
            {
                pre[j]=min(dp[i][j],pre[j-1]);
            }
        }
    }
    int ans=dp[n-1][0];
    for(int i=1;i<cnt;i++)
    {
        ans=min(ans,dp[n-1][i]);
    }
    printf("%d\n",ans);
    return 0;
}