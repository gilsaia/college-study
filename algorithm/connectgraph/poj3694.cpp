#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#define LL long long
#define Pr pair<int,int>
#define fread() freopen("in.in","r",stdin)
#define fwrite() freopen("out.out","w",stdout)
 
using namespace std;
const int INF = 0x3f3f3f3f;
const int msz = 10000;
const int mod = 1e9+7;
const double eps = 1e-8;
 
struct Edge
{
	int v,next;
};
 
Edge eg[666666];
int head[233333];
int dfn[233333],low[233333];
int pre[233333];
int fa[233333];
bool vis[233333];
int tp,tim;
int ans;
 
void init(int n)
{
	for(int i = 1; i <= n; ++i)
		pre[i] = i;
}
 
int Find(int x)
{
	return pre[x] == x? pre[x]: (pre[x] = Find(pre[x]));
}
 
int Union(int u,int v)
{
	int k = Find(u);
	int r = Find(v);
	if(k == r) return false;
	pre[k] = r;
	return true;
}
 
void Tarjan(int u,int p)
{
	vis[u] = 1;
	dfn[u] = low[u] = tim++;
	int v;
 
	for(int i = head[u]; i != -1; i = eg[i].next)
	{
		v = eg[i].v;
		if(v == p) continue;
 
		if(!vis[v])
		{
			fa[v] = u;
			Tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] > dfn[u])
			{
				ans++;
			}else Union(v,u);
		}
		else low[u] = min(low[u],dfn[v]);
	}
 
}
 
void lca(int u,int v)
{
	if(dfn[v] < dfn[u]) swap(u,v);
 
	while(dfn[v] > dfn[u])
	{
		if(Union(v,fa[v]))
			ans--;
		v = fa[v];
	}
 
	while(v != u)
	{
		if(Union(u,fa[u]))
			ans--;
		u = fa[u];
	}
 
}
 
int main()
{
	//fread();
	//fwrite();
 
	int n,m,u,v,z = 0;
 
	while(~scanf("%d%d",&n,&m) && (m+n))
	{
		memset(head,-1,sizeof(head));
		tim = tp = 0;
		init(n);
 
		while(m--)
		{
			scanf("%d%d",&u,&v);
			eg[tp].v = v;
			eg[tp].next = head[u];
			head[u] = tp++;
 
			eg[tp].v = u;
			eg[tp].next = head[v];
			head[v] = tp++;
		}
 
		memset(vis,0,sizeof(vis));
		ans = 0;
		fa[1] = 1;
		Tarjan(1,1);
 
		int q;
		scanf("%d",&q);
 
		printf("Case %d:\n",++z);
 
		while(q--)
		{
			scanf("%d%d",&u,&v);
			lca(u,v);
			printf("%d\n",ans);
		}
		puts("");
	}
 
	return 0;
}
