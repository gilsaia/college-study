#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
struct guest
{
	int val;
	string name;
};
guest fri[150020];
struct node
{
	int num, val;
	bool operator<(const node& rhs) const
	{
		if (val == rhs.val)
		{
			return num > rhs.num;
		}
		return val < rhs.val;
	}
};
struct indoor
{
    int t,p;
};
bool cmp(indoor a,indoor b)
{
    return a.t<b.t;
}
indoor invite[150020];
int res[150020];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int k, m, q;
		cin >> k >> m >> q;
		for (int i = 0; i < k; ++i)
		{
			cin >> fri[i].name >> fri[i].val;
		}
		int nowfri = 0, nowin = 0;
		priority_queue<node> que;
        for(int i=0;i<m;++i)
        {
            cin>>invite[i].t>>invite[i].p;
        }
        sort(invite,invite+m,cmp);
		for (int i = 0; i < m; ++i)
		{
            int t=invite[i].t,p=invite[i].p;
			while (nowfri < t)
			{
				++nowfri;
				node tmp;
				tmp.num = nowfri - 1;
				tmp.val = fri[nowfri - 1].val;
				que.push(tmp);
			}
			for (int i = 0; i < p; ++i)
			{
                if(que.empty())
                {
                    break;
                }
				++nowin;
				node tmp = que.top();
				que.pop();
				res[nowin] = tmp.num;
			}
		}
		while (nowfri < k)
		{
			++nowfri;
			node tmp;
			tmp.num = nowfri - 1;
			tmp.val = fri[nowfri - 1].val;
			que.push(tmp);
		}
		while (!que.empty())
		{
			++nowin;
			node tmp = que.top();
			que.pop();
			res[nowin] = tmp.num;
		}
		for (int i = 0; i < q; ++i)
		{
			int tmp;
			cin >> tmp;
			cout << fri[res[tmp]].name;
			if (i != q - 1)
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}