//emmmmmmmm似乎是二分图匹配的问题···然而思考了半天···放弃思考···下面是题解···大概意思明白了···但是还是感觉好难想···
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 2050
int map[maxn][maxn], used[maxn], edge[maxn], girl[maxn];
int n, m;
 
bool find(int x)
{
	int i;
	for (i = 0; i < maxn; i++)
	{
		if (map[x][i] && !used[i])
		{
			used[i] = 1;
			if (girl[i] == -1 || find(girl[i]))
			{
				girl[i] = x;
				return true;
			}
		}
	}
	return false;
}
 
int main()
{
	int i,j, num,temp,count;
	char s[15];
	while (scanf("%d%d", &n, &m), n + m)
	{
		memset(map, 0, sizeof(map));
		memset(girl, -1, sizeof(girl));
		count = 0;
		while (m--)
		{
			scanf("%s", s);
			num = 0; temp = -1;
			for (i = 0; i < strlen(s); i++)
			{
				if (s[i] == '*')
					temp = i;
				else
					num += (s[i] - '0')*(1 << strlen(s) - i - 1);
			}
			if (temp == -1)
				edge[count++] = num;
			else
			{
				edge[count++] = num;
				edge[count++] = num + (1 << strlen(s) - temp - 1);
			}
		}
		sort(edge, edge + count);
		int sum = 1;
		for (i = 1; i < count; i++)
			if (edge[i] != edge[i - 1])
				edge[sum++] = edge[i];//count中有可能出现重复的，所以要判重
		for (i = 0; i < sum; i++)
			for (j = 0; j < sum; j++)//这里算出的ans是两倍
			{
				int c1 = edge[i];
				int c2 = edge[j];
				int c = c1^c2;
				if (c && ((c&(c - 1)) == 0))//注意这里的括号不能节省，优先度比较麻烦干脆全写括号
					map[c1][c2] = 1;
			}
		int ans = 0;
		for (i = 0; i < maxn; i++)
		{
			memset(used, 0, sizeof(used));
			if (find(i))	
				ans++;
		}
		printf("%d\n",sum-ans/2);
	}
	return 0;
}
