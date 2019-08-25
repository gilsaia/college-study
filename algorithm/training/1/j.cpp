#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[6][120][120];
int main()
{
    int n,v1,v2,k;
    while(scanf("%d%d%d%d",&n,&v1,&v2,&k)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i)
        {
            int a,b,val;
            scanf("%d%d%d",&a,&b,&val);
 		for (int j = k; j >= 0; --j)
			{
				for (int m = v1; m >= a; --m)
				{
					for (int t = v2; t >= b; --t)
					{
						if (j != 0)
						{
							dp[j][m][t] = max(dp[j][m][t], dp[j - 1][m][t] + val);
						}
						dp[j][m][t]=max(dp[j][m][t],max(dp[j][m-a][t]+val,dp[j][m][t-b]+val));
					}
				}
				for(int m=v1;m>=a;--m)
				{
					for(int t=b-1;t>=0;--t)
					{
						if (j != 0)
						{
							dp[j][m][t] = max(dp[j][m][t], dp[j - 1][m][t] + val);
						}
						dp[j][m][t]=max(dp[j][m][t],dp[j][m-a][t]+val);
					}
				}
				for(int m=a-1;m>=0;--m)
				{
					for(int t=v2;t>=b;--t)
					{
						if (j != 0)
						{
							dp[j][m][t] = max(dp[j][m][t], dp[j - 1][m][t] + val);
						}
						dp[j][m][t]=max(dp[j][m][t],dp[j][m][t-b]+val);						
					}
				}
				if (j != 0)
				{
					for (int m = a - 1; m >= 0; --m)
					{
						for (int t = b - 1; t >= 0; --t)
						{
							dp[j][m][t] = max(dp[j][m][t], dp[j - 1][m][t] + val);
						}
					}
				}
			}
		}
        printf("%d\n",dp[k][v1][v2]);
    }
    return 0;
}