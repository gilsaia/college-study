#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int dp[100020][310];
int waittime[30];
char toattend[10020];
char seducle[100020];
int main()
{
	int k, n;
	scanf("%d%d", &k, &n);
	for (int i = 0; i < 26; ++i)
	{
		scanf("%d", &waittime[i]);
	}
	scanf("%s", toattend);
	scanf("%s", seducle);
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k+1; ++j)
		{
			if (dp[i - 1][j - 1] && seducle[i-1]!='\0'&&toattend[j-1]!='\0'&&seducle[i - 1] == toattend[j - 1])
			{
				int tmp = i+waittime[seducle[i - 1] - 'A'];
				if (tmp > n)
				{
					tmp = n;
				}
				dp[tmp][j] += dp[i - 1][j - 1];
				dp[tmp][j] %= MOD;
			}
			dp[i][j - 1] += dp[i - 1][j - 1];
			dp[i][j - 1] %= MOD;
		}
	}
	printf("%d\n", dp[n][k]);
	return 0;
}