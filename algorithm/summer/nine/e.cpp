#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int num[30];
int sum, _min, n, _minans;
bool inv[30];
int dfs(int step, int& con)
{
	if (step > con)
	{
		return 0;
	}
	if (abs(sum) < _min)
	{
		_min = abs(sum);
		_minans = step;
	}
	else if (abs(sum) == _min)
	{
		_minans = min(_minans, step);
	}
	if (_min == 0)
	{
		return 1;
	}
	if (sum < 0)
	{
		for (int i = 0; i < 9; ++i)
		{
			if (inv[i] == false && num[i] != 0)
			{
				int need = sum / (i - 9)/2;
				need = min(num[i], need);
				inv[i] = true;
				inv[18 - i] = true;
				num[i] -= need;
				num[18 - i] += need;
				sum -= (need * (i - 9) * 2);
				dfs(step + need, con);
				if (num[i])
				{
					--num[i], ++num[18 - i];
					sum -= ((i - 9) * 2);
					dfs(step + need + 1, con);
					sum += ((i - 9) * 2);
					--num[18 - i], ++num[i];
				}
				sum += (need * (i - 9) * 2);
				num[18 - i] -= need;
				num[i] += need;
			}
		}
	}
	else if (sum > 0)
	{
		for (int i = 18; i > 9; --i)
		{
			if (inv[i] == false&&num[i]!=0)
			{
				int need = sum / (i - 9)/2;
				need = min(num[i], need);
				inv[i] = true;
				inv[18 - i] = true;
				num[i] -= need;
				num[18 - i] += need;
				sum -= (need * (i - 9) * 2);
				dfs(step + need, con);
				if (num[i])
				{
					--num[i], ++num[18 - i];
					sum -= ((i - 9)*2);
					dfs(step + need + 1, con);
					sum += ((i - 9)*2);
					--num[18 - i], ++num[i];
				}
				sum += (need * (i - 9) * 2);
				num[18 - i] -= need;
				num[i] += need;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		++num[x - y + 9];
		sum += (x - y);
	}
	_min = abs(sum);
	_minans = 0;
	dfs(0, n);
	printf("%d\n", _minans);
	return 0;
}