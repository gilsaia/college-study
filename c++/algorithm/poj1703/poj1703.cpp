//并查集维护不同序列的问题，方法是将n扩展二倍后维护不同集合，与食物链类似
//另：自己写的一开始tle后来改进好几次之后又wa实在是不想改正就找了一份题解
#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
const int maxn = 1e5 + 5;
 
int n, m;
int par[maxn*2], high[maxn*2];
 
void init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		par[i] = i;
		high[i] = 0;
	}
}
 
int getRoot(int x)
{
	return par[x] == x ? x : par[x] = getRoot(par[x]);
}
 
void unite(int x, int y)
{
	x = getRoot(x);
	y = getRoot(y);
	if(x == y)	return;
 
	if(high[x] < high[y])	par[x] = y;
	else
	{
		par[y] = x;
		if(high[x] == high[y])	high[x]++;
	}
}
 
bool same(int x, int y)
{
	return getRoot(x) == getRoot(y);
}
 
int main()
{
	//freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--)
	{
		scanf("%d%d", &n, &m);
		init(2*n);
 
		char op;	int a, b;
		for(int i = 1; i <= m; i++)
		{
			scanf("\n%c%d%d", &op, &a, &b);
			if(op == 'D')
			{
				unite(a, b+n);
				unite(a+n, b);
			}
			else
			{
				if(same(a, b+n) || same(a+n, b))	printf("In different gangs.\n");
				else if(same(a, b) || same(a+n, b+n))	printf("In the same gang.\n");
				else	printf("Not sure yet.\n");
			}
		}
	}
    return 0;
}