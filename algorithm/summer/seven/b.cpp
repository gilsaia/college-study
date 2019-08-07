#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll save[10020];
int main()
{
	ll minindex = 1;
	ll a1, m;
	scanf("%lld%lld", &a1, &m);
	save[1] = a1;
	priority_queue<int,vector<int>,greater<int>> que;
	que.push(a1);
	if (a1 == 1)
	{
		++minindex;
	}
	if (a1 == m)
	{
		printf("1\n");
		return 0;
	}
	int ans = 0;
	for (int i = 2; i <= 10000; ++i)
	{
		ll tmp = save[i - 1] + minindex;
		que.push(tmp);
		save[i] = tmp;
		if (m == tmp || m == minindex)
		{
			ans = i;
			break;
		}
		int find = 0;
		for (int j = i - 1; j >= 1; --j)
		{
			if ((save[i] - save[j]) > minindex&&(save[i] - save[j]) <= 1e7)
			{
				que.push(save[i] - save[j]);
			}
			if (save[i] - save[j] == m)
			{
				ans = i;
				find = 1;
			}
		}
		if (find)
		{
			break;
		}
		while (true)
		{
			while (!que.empty() && minindex >= que.top())
			{
				que.pop();
			}
			++minindex;
			if (que.empty())
			{
				break;
			}
			if (que.top() > minindex)
			{
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}