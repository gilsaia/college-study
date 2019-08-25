#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int dfn[2600], low[2600], scc[2600];
int dfn_index = 0, scc_index = 0;
int on_stack[2600];
int stack[2600];
int st = 0;
vector<int> G[2600];
void tarjan(int u)
{
	dfn[u] = low[u] = ++dfn_index;
	on_stack[u] = 1; stack[st++] = u;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (!dfn[v])
		{
			// 树边的情况
			tarjan(v);
			if (low[v] < low[u])
				low[u] = low[v];
		}
		else if (on_stack[v] && dfn[v] < low[u]) {
			// 横叉边或者反祖边的情况
			low[u] = dfn[v];
		}
	}

	if (low[u] == dfn[u])
	{
		int tmp = 0;
		++scc_index;
		while (tmp != u)
		{
			tmp = stack[--st];
			scc[tmp] = scc_index;
			on_stack[tmp] = 0;
		}
	}
}
int tosave[2600][2600];
int nodesize[2600];
int main()
{
	int n;
	scanf("%d", &n);
	int nowhave = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &tosave[i][j]);
			if (tosave[i][j] == 1)
			{
				nowhave++;
				G[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!dfn[i])
		{
			tarjan(i);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		nodesize[scc[i]]++;
	}
	int sum = n * (n - 1);
	sum -= nowhave;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			sum -= nodesize[i] * nodesize[j];
		}
	}
	printf("%d\n", sum);
	return 0;
}