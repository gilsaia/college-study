#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e6 + 10;
int par[MAXN], val[MAXN];
void init(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		par[i] = i, val[i] = 0;
	}
}
int find(int x)
{
	if (x == par[x])
	{
		return x;
	}
	int fa = par[x];
	par[x] = find(par[x]);
	val[x] ^= val[fa];
	return par[x];
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
void unite(int x, int y, int valne)
{
	int tx = find(x);
	int ty = find(y);
	if (tx == ty)
	{
		return;
	}
	par[tx] = ty;
	val[tx] = valne ^ val[x] ^ val[y];
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, c;
		scanf("%d%d", &n, &c);
		init(n);
		for (int i = 0; i < n - 1; ++i)
		{
			int tmp, tmp2;
			scanf("%d%d", &tmp, &tmp2);
		}
		int ans = c;
		for (int i = 0; i < c; ++i)
		{
			int x, y, valne;
			scanf("%d%d%d", &x, &y, &valne);
			if (ans != c)
			{
				continue;
			}
			if (same(x, y) && ((val[x] ^ val[y]) != valne))
			{
				ans = i;
			}
			else
			{
				unite(x, y, valne);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}