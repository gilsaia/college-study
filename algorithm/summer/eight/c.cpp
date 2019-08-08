#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int val[1600][1600], ran[1600][1600];
int init[1600][1600];
char str[1600][1600];
struct node
{
	int val, num;
	bool operator<(const node& rhs) const
	{
		if (val == rhs.val)
		{
			return num < rhs.num;
		}
		return val < rhs.val;
	}
};
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				char tmp[3];
				scanf("%d%s", &init[i][j],tmp);
				str[i][j] = tmp[0];
			}
		}
		memset(val, 0, sizeof(val));
		memset(ran, 0, sizeof(ran));
		val[1][1] = init[1][1];
		for (int i = 2; i <= n; ++i)
		{
			vector<node> vec;
			for (int j = 1; j <= i; ++j)
			{
				val[i][j] = max(val[i - 1][j - 1], val[i - 1][j]) + init[i][j];
				ran[i][j] = INF;
				if (j > 1 && (val[i][j] == (val[i - 1][j - 1] + init[i][j])))
				{
					ran[i][j] = min(ran[i][j], (str[i][j] - 'a') * 10000 + ran[i - 1][j - 1]);
				}
				if (j < i && (val[i][j] == (val[i - 1][j] + init[i][j])))
				{
					ran[i][j] = min(ran[i][j], (str[i][j] - 'a') * 10000 + ran[i - 1][j]);
				}
				node tmp;
				tmp.num = j, tmp.val = ran[i][j];
				vec.push_back(tmp);
			}
			sort(vec.begin(), vec.end());
			int newrank = 1, newvalue = vec[0].val;
			for (int j = 0; j < vec.size(); ++j)
			{
				if (vec[j].val != newvalue)
				{
					++newrank;
					newvalue = vec[j].val;
				}
				ran[i][vec[j].num] = newrank;
			}
		}
		int maxval = 0;
		for (int i = 1; i <= n; ++i)
		{
			maxval = max(maxval, val[n][i]);
		}
		vector<node> vec;
		for (int i = 1; i <= n; ++i)
		{
			if (val[n][i] == maxval)
			{
				node tmp;
				tmp.val = ran[n][i];
				tmp.num = i;
				vec.push_back(tmp);
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); ++i)
		{
			printf("%d", vec[i].num);
			if (i != vec.size() - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}