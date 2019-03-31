#include<set>
#include<utility>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> edge;
const ll MAXN = 0xfffffffffffffff;
struct edges
{
	ll value;
	set<edge> inside;
};
vector<edges> whole[502][502];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				whole[i][j].clear();
			}
		}
		vector<edge> order;
		for (int i = 0; i < m; ++i)
		{
			edge tmp;
			int value;
			edges toinsert;
			scanf("%d%d%d", &tmp.first, &tmp.second, &value);
			--tmp.first, --tmp.second;
			toinsert.inside.insert(tmp);
			toinsert.value = value;
			whole[tmp.first][tmp.second].push_back(toinsert);
			order.push_back(tmp);
		}
		for (int k = 0; k < n; ++k)
		{
			for (int i = 0; i < n; ++i)
			{
				if (i == k)
				{
					continue;
				}
				for (int j = 0; j < n; ++j)
				{
					if (k == j)
					{
						continue;
					}
					if (i == j)
					{
						continue;
					}
					edge findthis;
					findthis.first = i, findthis.second = j;
					for (int t = 0; t < whole[i][k].size(); ++t)
					{
						for (int q = 0; q < whole[k][j].size(); ++q)
						{
							if ((whole[i][k][t].inside.find(findthis) == whole[i][k][t].inside.end()) && (whole[k][j][q].inside.find(findthis) == whole[k][j][q].inside.end()))
							{
								edges tmp;
								tmp.value = whole[i][k][t].value + whole[k][j][q].value;
								tmp.inside.insert(whole[i][k][t].inside.begin(), whole[i][k][t].inside.end());
								tmp.inside.insert(whole[k][j][q].inside.begin(), whole[k][j][q].inside.end());
								whole[i][j].push_back(tmp);
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < m; ++i)
		{
			ll ans = MAXN;
			edge tmp = order[i];
			for (int j = 1; j < whole[tmp.first][tmp.second].size(); ++j)
			{
				ans = min(MAXN, whole[tmp.first][tmp.second][j].value);
			}
			if (ans == MAXN)
			{
				ans = 0;
			}
			printf("%lld\n", ans);
		}
		printf("\n");
	}
	return 0;
}