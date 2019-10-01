#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int msz = 10000;
const double eps = 1e-8;
 
bool mp[233][233];
int dfn[233],low[233];
bool vis[233];
bool flag[233];
int tim,n,cnt;
 
void tarjan(int u,int pre)
{
	vis[u] = 1;
	dfn[u] = low[u] = tim++;
 
	int k = 0;
	for(int v = 1; v <= n; ++v)
	{
		if(!mp[u][v]) continue;
		if(!vis[v])
		{
			++k;
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if((u == 1 && k == 2) || (u != 1 && low[v] >= dfn[u]))
				flag[u] = 1;
		}
		else low[u] = min(low[u],dfn[v]);
	}
	cnt += flag[u];
}
 
void init()
{
	memset(mp,0,sizeof(mp));
	memset(flag,0,sizeof(flag));
	memset(vis,0,sizeof(vis));
	cnt = tim = 0;
}
int main()
{
	int u,v;
	while(~scanf("%d",&n) && n)
	{
		init();
		while(~scanf("%d",&u) && u)
		{
			while(getchar() != '\n')
			{
				scanf("%d",&v);
				mp[u][v] = mp[v][u] = 1;
			}
		}
 
		tarjan(1,1);
 
		printf("%d\n",cnt);
	}
	return 0;
}