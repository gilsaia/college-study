#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN=22000;
const int MOD=1E9+7;
struct Edge
{
	int to, val;
	Edge(int v, int w): to(v), val(w) {}
};
int n, siz, root;
int sz[MAXN], mx[MAXN];
int dis[MAXN], cnt[3], sum[3], ans[3];
bool vis[MAXN];
vector<Edge> g[MAXN];
void getroot(int u, int f)
{
	sz[u]=1; mx[u]=0;
	for (int i=0; i<g[u].size(); i++)
	{
		int v=g[u][i].to;
		if (vis[v]||v==f) continue;
		getroot(v, u);
		sz[u]+=sz[v]; mx[u]=max(mx[u], sz[v]);
	}
	mx[u]=max(mx[u], siz-sz[u]);
	if (mx[u]<mx[root]) root=u;
}
void getdis(int u, int f)
{
	cnt[dis[u]%3]++;
	sum[dis[u]%3]=(sum[dis[u]%3]+dis[u])%MOD;
	for (int i=0; i<g[u].size(); i++)
	{
		int v=g[u][i].to, w=g[u][i].val;
		if (vis[v]||v==f) continue;
		dis[v]=dis[u]+w;
		getdis(v, u);
	}
}
void calc(int u, int w, int k)
{
	dis[u]=w;
	cnt[0]=cnt[1]=cnt[2]=0;
	sum[0]=sum[1]=sum[2]=0;
	getdis(u, 0);
	ans[0]=((ans[0]+k*(2ll*sum[0]*cnt[0]+2ll*sum[1]*cnt[2]+2ll*sum[2]*cnt[1]))%MOD+MOD)%MOD;
	ans[1]=((ans[1]+k*(2ll*sum[2]*cnt[2]+2ll*sum[0]*cnt[1]+2ll*sum[1]*cnt[0]))%MOD+MOD)%MOD;
	ans[2]=((ans[2]+k*(2ll*sum[1]*cnt[1]+2ll*sum[0]*cnt[2]+2ll*sum[2]*cnt[0]))%MOD+MOD)%MOD;
}
void solve(int u)
{
	calc(u, 0, 1); vis[u]=1;
	for (int i=0; i<g[u].size(); i++)
	{
		int v=g[u][i].to, w=g[u][i].val;
		if (vis[v]) continue;
		calc(v, w, -1);
		root=0; siz=sz[v];
		getroot(v, 0);
		solve(root);
	}
}
int main()
{
//	freopen("D.in", "r", stdin);
//	freopen("D.out", "w", stdout);
	while (~scanf("%d", &n))
	{
		for (int i=1; i<=n; i++) g[i].clear();
		for (int i=1, u, v, w; i<n; i++)
		{
			scanf("%d%d%d", &u, &v, &w); u++; v++;
			g[u].push_back(Edge(v, w));
			g[v].push_back(Edge(u, w));
		}
		root=0; mx[0]=siz=n;
		memset(vis, 0, sizeof vis);
		getroot(1, 0);
		ans[0]=ans[1]=ans[2]=0;
		solve(root);
		printf("%d %d %d\n", ans[0], ans[1], ans[2]);
	}
	return 0;
}