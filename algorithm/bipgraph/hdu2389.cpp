#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define INF 99999999;
using namespace std;
 
struct People
{
	double x;
	double y;
	double t;
};
 
struct Umbrella
{
	double x;
	double y;
};
 
int T;
int time;//约束时间
int pNum;//人的数目
int uNum;//伞的数目
People people[3005];
Umbrella umbrella[3005];
int dis;
int cx[3005];
int cy[3005];
int dx[3005];
int dy[3005];
bool g[3005][3005];
bool vis[3005];
 
double distance(People p, Umbrella u)
{
	return sqrt((p.x - u.x)*(p.x - u.x) + (p.y - u.y)*(p.y - u.y));
}
 
bool searchPath()
{
	dis = INF;
	queue<int> Q;
	memset(dx, -1, sizeof(dx));
	memset(dy, -1, sizeof(dy));
	for (int i = 0; i < pNum; i++)
	{
		if (cx[i] == -1)
		{
			Q.push(i);
			dx[i] = 0;
		}
	}
 
 
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		if (dx[u] > dis)
			break;
		for (int v = 0; v < uNum; v++)
		{
			if (g[u][v] && dy[v] == -1)
			{
				dy[v] = dx[u] + 1;
				if (cy[v] == -1)
					dis = dy[v];
				else
				{
					dx[cy[v]] = dy[v] + 1;
					Q.push(cy[v]);
				}
			}
		}
	}
	
	return dis != INF;
}
 
int dfs(int u)
{
	for (int v = 0; v < uNum; v++)
	{
		if (g[u][v] && dy[v] == dx[u] + 1 && !vis[v])
		{
			vis[v] = 1;
			if (cy[v] != -1 && dy[v] == dis)
				continue;
			if (cy[v] == -1 || dfs(cy[v]))
			{
				cx[u] = v;
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}
 
int HK()
{
	int ans = 0;
	memset(cx, -1, sizeof(cx));
	memset(cy, -1, sizeof(cy));
	while (searchPath())
	{
		memset(vis, 0, sizeof(vis));
		for (int u = 0; u < pNum; u++)
		{
			if (cx[u] == -1)
				ans += dfs(u);
		}
	}
	return ans;
}
 
int main()
{
	scanf("%d", &T);
	int cas = 1;
	while (T--)
	{
		scanf("%d%d", &time, &pNum);
		for (int i = 0; i < pNum; i++)
			scanf("%lf%lf%lf", &people[i].x, &people[i].y, &people[i].t);
		scanf("%d", &uNum);
		for (int i = 0; i < uNum; i++)
			scanf("%lf%lf", &umbrella[i].x, &umbrella[i].y);
 
		memset(g, 0, sizeof(g));
 
		for (int i = 0; i < pNum; i++)
			for (int j = 0; j < uNum; j++)
				if (distance(people[i], umbrella[j]) / people[i].t <= time)
					g[i][j] = 1;
		
		printf("Scenario #%d:\n%d\n\n", cas++, HK());
	}
	return 0;
}