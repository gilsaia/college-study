#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<int> parent[30], son[30];
int ord[30];
int dfn[100], low[100], scc[100];
int dfn_index = 0, scc_index = 0;
int on_stack[100];
int stack[100];
int st = 0;
vector<int> G[100];
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
int main()
{
	char tmp;
	int n;
	scanf("%c %d", &tmp, &n);
	int num = tmp - 'a';
	char nowpro[2][2020];
	scanf("%s", nowpro[0]);
	for (int i = 1; i < n; ++i)
	{
		scanf("%s", nowpro[i % 2]);
		for (int j = 0; nowpro[i % 2][j] != '\0' && nowpro[(i + 1) % 2][j] != '\0'; ++j)
		{
			if (nowpro[i % 2][j] != nowpro[(i + 1) % 2][j])
			{
				int f = nowpro[(i + 1) % 2][j] - 'a', s = nowpro[i % 2][j] - 'a';
				son[f + 1].push_back(s + 1);
				parent[s + 1].push_back(f + 1);
				G[s+1].push_back(f+1);
				break;
			}
		}
	}
	for (int i = 1; i <= (num + 1); ++i)
	{
		if (!dfn[i])
		{
			tarjan(i);
		}
	}
	int ans = 0, entrysiz = 0,quitsiz=0;
	int lastentry;
	for (int i = 1; i <= (num + 1); ++i)
	{
		if (parent[i].empty() && son[i].empty())
		{
			ans = -2;
			break;
		}
		if (parent[i].size() == 0)
		{
			++entrysiz;
			lastentry = i;
			if (entrysiz >= 2)
			{
				ans = -2;
				break;
			}
		}
		if (son[i].size() == 0)
		{
			++quitsiz;
			if (quitsiz >= 2)
			{
				ans = -2;
				break;
			}
		}
	}
	for (int i = 1; i <= (num + 1); ++i)
	{
		for (int j = 0; j < G[i].size(); ++j)
		{
			if (scc[i] != 0 && scc[G[i][j]] != 0 && scc[i] == scc[G[i][j]])
			{
				ans = -1;
				break;
			}
		}
		if (ans == -1)
		{
			break;
		}
	}
	if (ans == -1)
	{
		printf("IMPOSSIBLE\n");
	}
	else if (ans == -2)
	{
		printf("AMBIGUOUS\n");
	}
	else
	{
		char res[30];
		for (int i = 0; i <=num; ++i)
		{
			res[scc[i + 1] - 1] = i + 'a';
		}
		res[num + 1] = '\0';
		printf("%s\n", res);
	}
	return 0;
}