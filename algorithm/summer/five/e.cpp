#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int candi[100020];
int len[100020];
int par[100020];
void init(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		par[i] = i;
	}
}
int find(int x)
{
	if (x == par[x])
	{
		return x;
	}
	return par[x] = find(par[x]);
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	par[x] = y;
}
struct node
{
	int start, end, value;
	bool operator<(const node& rhs) const
	{
		return value > rhs.value;
	}
};
int main()
{
	int L, S;
	while (~scanf("%d%d", &L, &S))
	{
		if (L == 0)
		{
			break;
		}
		for (int i = 0; i < L; ++i)
		{
			scanf("%d", &candi[i]);
		}
		init(L);
		sort(candi, candi + L);
		priority_queue<node> que;
		for (int i = 1; i < L; ++i)
		{
			node x;
			x.start = i - 1, x.end = i, x.value = candi[i] - candi[i - 1];
			len[i - 1] = candi[i] - candi[i - 1];
			que.push(x);
		}
		int time = 0;
		while (time < (L-S))
		{
			node tmp = que.top();
			que.pop();
			int mervalue = 0x3f3f3f, mergenode = -1;
			if (tmp.start > 0)
			{
				if (same(tmp.start, tmp.start - 1))
				{
					continue;
				}
				if (len[tmp.start - 1] < mervalue)
				{
					mervalue = len[tmp.start - 1];
					mergenode = 1;
				}
			}
			if (tmp.end < (L - 1))
			{
				if (same(tmp.end - 1, tmp.end))
				{
					continue;
				}
				if (len[tmp.end] < mervalue)
				{
					mervalue = len[tmp.end];
					mergenode = 2;
				}
			}
			if (mergenode == 1)
			{
				int merend = tmp.start - 1;
				int merstr = tmp.start - 1;
				while (merstr > 0 && same(merend, merstr - 1))
				{
					--merstr;
				}
				node next = tmp;
				next.start = merstr;
				next.value += len[merend];
				unite(next.start, next.end - 1);
				len[merstr] = next.value;
				len[next.end - 1] = next.value;
				que.push(next);
				time++;
			}
			else if (mergenode == 2)
			{
				int merend = tmp.end;
				int merstr = tmp.end;
				while (merend < (L - 1) && same(merstr, merend + 1))
				{
					++merend;
				}
				node next = tmp;
				next.end = merend + 1;
				next.value += len[merstr];
				unite(next.start, next.end - 1);
				len[merend] = next.value;
				len[next.start] = next.value;
				que.push(next);
				++time;
			}
		}
		int ans = -1;
		while (!que.empty())
		{
			node tmp = que.top();
			que.pop();
			if (tmp.start > 0)
			{
				if (same(tmp.start, tmp.start - 1))
				{
					continue;
				}
			}
			if (tmp.end <= (L - 1))
			{
				if (same(tmp.end-1, tmp.end))
				{
					continue;
				}
			}
			ans = tmp.value;
			break;
		}
		printf("%d\n", ans);
	}
	return 0;
}