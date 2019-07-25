#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
int isrem[10020];
ll val[10020];
int dag[10020];
int par[10020], siz[10020];
vector<int> G[10020];
void init(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		par[i] = i;
		siz[i] = 1;
	}
}
int find(int x)
{
	if (x == par[x])
	{
		return x;
	}
	return par[x] = find(par[x]);
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	par[x] = y;
	siz[y] += siz[x];
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int p, m;
		scanf("%d%d", &p, &m);
		for (int i = 1; i <= p; ++i)
		{
			scanf("%lld", &val[i]);
			isrem[i] = 0;
			dag[i] = 0;
            G[i].clear();
		}
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			++dag[u], ++dag[v];
			G[u].push_back(v);
			G[v].push_back(u);
		}
		queue<int> que;
		for (int i = 1; i <= p; ++i)
		{
			if (dag[i] == 0 || dag[i] == 1)
			{
				que.push(i);
				isrem[i] = 1;
			}
		}
		while (!que.empty())
		{
			int tmp = que.front();
			que.pop();
			for (int i = 0; i < G[tmp].size(); ++i)
			{
				if (isrem[G[tmp][i]] == 0)
				{
					--dag[G[tmp][i]];
					if (dag[G[tmp][i]] < 2)
					{
						que.push(G[tmp][i]);
						isrem[G[tmp][i]] = 1;
					}
				}
			}
		}
		init(p);
		for (int i = 1; i <= p; ++i)
		{
			if (isrem[i])
			{
				continue;
			}
			for (int j = 0; j < G[i].size(); ++j)
			{
				if (isrem[G[i][j]])
				{
					continue;
				}
				if (!same(i, G[i][j]))
				{
					unite(i, G[i][j]);
				}
			}
		}
		ll ans = 0;
		for (int i = 1; i <= p; ++i)
		{
			if (isrem[i])
			{
				continue;
			}
			if (siz[find(i)] & 1)
			{
				ans += val[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}