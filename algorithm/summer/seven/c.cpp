#include<vector>
#include<string.h>
#include<cstdio>
#include<algorithm>
using namespace std;
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
struct node
{
	int num, dif;
};
node diff[100];
bool cmp(node a, node b)
{
	return a.dif > b.dif;
}
int tosave[50][50];
int main()
{
	int N, M, starttor = 1;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		int num;
		scanf("%d", &num);
		char seq[100];
		scanf("%s", seq);
		for (int j = 0; j < N; ++j)
		{
			for (int t = j + 1; t < N; ++t)
			{
				tosave[seq[j] - 'A'+1][seq[t] - 'A'+1] += num;
			}
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = i + 1; j <= N; ++j)
		{
			if (tosave[i][j] > tosave[j][i])
			{
				if (starttor == i)
				{
					starttor = j;
				}
				G[j].push_back(i);
			}
			else
			{
				if (starttor == j)
				{
					starttor = i;
				}
				G[i].push_back(j);
			}
		}
	}
	tarjan(starttor);
	for (int i = 1; i <= N; ++i)
	{
		if (!dfn[i])
		{
			tarjan(i);
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		char tmp = 'A' + i-1;
		printf("%c: ", tmp);
		if (scc[i] == 1)
		{
			printf("can win\n");
		}
		else
		{
			printf("can't win\n");
		}
	}
	return 0;
}