#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct edge
{
	int to, forced;
	edge()
	{
		forced = 0;
		to = 0;
	}
};
vector<edge> G[1020];
int visit[1020][2];
int canstop[1020];
struct node
{
	int nowpos, havebug;
};
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int from, to;
		scanf("%d%d", &from, &to);
		edge tmp;
		if (from < 0)
		{
			tmp.forced = 1;
			from = -from;
		}
		tmp.to = to;
		G[from].push_back(tmp);
	}
	node start;
	start.nowpos = 1, start.havebug = 1;
	visit[1][1] = 1;
	queue<node> que;
	que.push(start);
	while (!que.empty())
	{
		node tmp = que.front();
		que.pop();
		int haveforce = 0;
		for (int i = 0; i < G[tmp.nowpos].size(); ++i)
		{
			edge nextedge = G[tmp.nowpos][i];
			if (nextedge.forced == 1)
			{
				haveforce = 1;
				if (visit[nextedge.to][tmp.havebug] == 0)
				{
					node next = tmp;
					next.nowpos = nextedge.to;
					visit[next.nowpos][next.havebug] = true;
					que.push(next);
				}
			}
			if (nextedge.forced == 0 && tmp.havebug == 1 && visit[nextedge.to][0] == 0)
			{
				node next = tmp;
				next.nowpos = nextedge.to;
				next.havebug = 0;
				visit[next.nowpos][next.havebug] = true;
				que.push(next);
			}
		}
		if (haveforce == 0)
		{
			canstop[tmp.nowpos] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i)
	{
		if (canstop[i])
		{
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}