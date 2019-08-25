#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
int face[12];
int ans[2010][12];
int dp[2010];
int main()
{
	int torec;
	while (~scanf("%d", &torec))
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &face[i]);
		}
		memset(dp, INF, sizeof(dp));
		memset(ans, 0, sizeof(ans));
		dp[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= torec; ++j)
			{
				if ((j + face[i]) <= torec)
				{
					if (dp[j + face[i]] >= dp[j] + 1)
					{
						dp[j + face[i]] = dp[j] + 1;
						for (int t = 0; t <= i; ++t)
						{
							ans[j + face[i]][t] = ans[j][t];
						}
						++ans[j + face[i]][i];
					}
				}
			}
		}
		if (dp[torec] == INF)
		{
			printf("-1\n");
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				printf("%d", ans[torec][i]);
				if (i != (n - 1))
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}