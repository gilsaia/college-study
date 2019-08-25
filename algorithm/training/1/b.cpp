#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
struct edge
{
	int to, cap, rev;
};
ll a[120],b[120];
vector<edge> G[240];
bool used[240];
int INF=1e7;
void add_edge(int from, int to, int cap)
{
	edge tmp;
	tmp.to = to, tmp.cap = cap, tmp.rev = G[to].size();
	G[from].push_back(tmp);
	tmp.to = from, tmp.cap = 0, tmp.rev = G[from].size() - 1;
	G[to].push_back(tmp);
}
int dfs(int v, int t, int f)
{
	if (v == t)
	{
		return f;
	}
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i)
	{
		edge& e = G[v][i];
		if (!used[e.to] && e.cap > 0)
		{
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s, int t)
{
	int flow = 0;
	for (;;)
	{
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0)
		{
			return flow;
		}
		flow += f;
	}
}
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i)
    {
        scanf("%d",&a[i]);
        add_edge(i*2+1,1,a[i]);
    }
    for(int i=1;i<=N;++i)
    {
        scanf("%d",&b[i]);
        add_edge(0,i*2,b[i]);
    }

    ll ans=0;
    for(int i=0;i<M;++i)
    {
        int at,bt;
        scanf("%d%d",&at,&bt);
        add_edge(at*2,bt*2+1,INF);
    }
    ans=max_flow(0,1);
    printf("%lld\n",ans);
    return 0;
}