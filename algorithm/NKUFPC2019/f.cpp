#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int MAXN = 100020;
struct node
{
	int value;
	node *next;
};
vector<node*> save[260];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		for (int i = 0; i < 260; ++i)
		{
			for (int j = 0; j < save[i].size(); ++j)
			{
				delete save[i][j];
			}
			save[i].clear();
		}
		string origin, tocmp;
		node *last;
		cin >> origin >> tocmp;
		last = new node;
		last->value = origin[0];
		for (int i = 1; i < a; ++i)
		{
			node *tmp = new node;
			tmp->value = origin[i];
			last->next = tmp;
			save[last->value].push_back(last);
			last = tmp;
		}
		last->next = nullptr;
		save[last->value].push_back(last);
		ll ans = 0;
		for (int i = 0; i < b; ++i)
		{
			queue<node*> que[2];
			ans += save[tocmp[i]].size();
			for (int j = 0; j < save[tocmp[i]].size(); ++j)
			{
				if ((i + 1) < b&&save[tocmp[i]][j]->next!=nullptr && save[tocmp[i]][j]->next->value == tocmp[i + 1])
				{
					que[(i + 1) % 2].push(save[tocmp[i]][j]->next);
				}
			}
			for (int j = i + 1; j < b; ++j)
			{
				if(que[j%2].empty())
                {
                    break;
                }
                while (!que[j % 2].empty())
				{
					node *tmp = que[j % 2].front();
					++ans;
					que[j % 2].pop();
					if ((j + 1) < b&&tmp->next != nullptr&&tmp->next->value == tocmp[j + 1])
					{
						que[(j + 1) % 2].push(tmp->next);
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}