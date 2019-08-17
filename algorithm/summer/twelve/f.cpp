#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct node
{
	int num, cost;
	node(int _num = 0, int _cost = 0)
	{
		num = _num;
		cost = _cost;
	}
};
bool cmp1(node a, node b)
{
	return a.cost < b.cost;
}
bool cmp2(node a, node b)
{
	return a.cost > b.cost;
}
int cost[10020];
char sour[10020], goal[10020];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &cost[i]);
	}
	scanf("%s%s", sour, goal);
	vector<node> one, zerotoone, actuchange;
	ll nowcost = 0;
	for (int i = 0; i < n; ++i)
	{
		if (sour[i] == '1')
		{
			one.push_back(node(i, cost[i]));
			nowcost += cost[i];
		}
		else if (sour[i] == '0' && goal[i] == '1')
		{
			zerotoone.push_back(node(i, cost[i]));
		}
	}
	sort(one.begin(), one.end(), cmp2);
	ll ans = INF, sum = nowcost;
	int len = one.size();
	for (int i = -1; i < len; ++i)
	{
		nowcost = sum;
		ll turn = 0;
		actuchange = zerotoone;
		for (int j = 0; j <= i; ++j)
		{
			nowcost -= one[j].cost;
			turn += nowcost;
			if (goal[one[j].num] == '1')
			{
				actuchange.push_back(node(one[j].num, one[j].cost));
			}
			if (turn > ans)
			{
				break;
			}
		}
		if (turn > ans)
		{
			continue;
		}
		for (int j = i+1; j < one.size(); ++j)
		{
			if (goal[one[j].num] == '0')
			{
				nowcost -= one[j].cost;
				turn += nowcost;
				if (turn > ans)
				{
					break;
				}
			}
		}
		if (turn > ans)
		{
			continue;
		}
		sort(actuchange.begin(), actuchange.end(), cmp1);
		for (int j = 0; j < actuchange.size(); ++j)
		{
			nowcost += actuchange[j].cost;
			turn += nowcost;
			if (turn > ans)
			{
				break;
			}
		}
		if (turn > ans)
		{
			continue;
		}
		ans = min(ans, turn);
	}
	printf("%lld\n", ans);
	return 0;
}