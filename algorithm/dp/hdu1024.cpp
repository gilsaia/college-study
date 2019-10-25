#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000002;
const int INF=0x3f3f3f3f;
int dp[MAXN][2],num[MAXN];
int main()
{
    int n,m;
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&num[i]);
        }
        memset(dp,0,sizeof(dp));
        int tmp;
        for(int i=0;i<m;++i)
        {
            tmp=-INF;
            for(int j=i+1;j<=n;++j)
            {
                dp[j][0]=max(dp[j-1][0]+num[j],dp[j-1][1]+num[j]);
                dp[j-1][1]=tmp;
                tmp=max(tmp,dp[j][0]);
            }
        }
        printf("%d\n",tmp);
    }
    return 0;
}