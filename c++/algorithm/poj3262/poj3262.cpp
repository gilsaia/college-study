//贪心算法分析错误，应根据单位时间吃的花与所需时间排序；
#include<stdio.h>
#include<algorithm>
using namespace std;
struct cow
{
	int time, des;
}cows[100010];
bool cmp(cow a, cow b)
{
	return a.time*b.des<a.des*b.time;
    /*if (a.des > b.des)
	{
		return true;
	}
	else
	{
		if (a.des < b.des)
		{
			return false;
		}
		else
		{
			return a.time < b.time;
		}
	}*/
}
int main()
{
	long long n,destory=0;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &cows[i].time, &cows[i].des);
		destory += cows[i].des;
	}
	sort(cows, cows + n, cmp);
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		destory -= cows[i].des;
		ans += destory*cows[i].time * 2;
	}
	printf("%lld\n", ans);
    system("pause");
	return 0;
}