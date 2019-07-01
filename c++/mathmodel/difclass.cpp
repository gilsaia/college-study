#include<fstream>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
struct node
{
	int num;
	double par[50];
};
double dis(node a, node b)
{
	double res=0;
	for(int i=0;i<50;++i)
	{
		res+=(abs(a.par[i]-b.par[i])*abs(a.par[i]-b.par[i]));
	}
	return res;
}
bool operator<(node a, node b)
{
	node tmp;
	return dis(a, tmp) < dis(b, tmp);
}
struct edge
{
	int from, to;
	double value;
	bool operator<(const edge& rhs) const
	{
		return value > rhs.value;
	}
};
int par[4010];
void init(int n)
{
	for (int i = 0; i < n; ++i)
	{
		par[i] = i;
	}
}
int find(int x)
{
	if (par[x] == x)
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
vector<node> vec;
int refer[4000];
void read(string inputpath)
{
	ifstream in(inputpath);
	while (!in.eof())
	{
		node tmp;
		for(int i=0;i<50;++i)
		{
			in>>tmp.par[i];
		}
		in>>tmp.num;
		vec.push_back(tmp);
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		refer[vec[i].num] = i;
	}
}
void k_means(priority_queue<edge> & que, int& n)
{
	int neededge = vec.size() - n;
	int nowedge = 0;
	init(4000);
	while (!que.empty())
	{
		edge tmp = que.top();
		que.pop();
		int v = tmp.from, u = tmp.to;
		if (same(v, u))
		{
			continue;
		}
		unite(u, v);
		++nowedge;
		if (nowedge == neededge)
		{
			break;
		}
	}
	n += (neededge - nowedge);
	return;
}
const int MAX_EDGE = 4000;
const int MAX_CLASS = 20;
int main()
{
	string inputpath = "D:\\mathmodel\\data\\ggds\\debug.txt";
	string outputpath = "D:\\mathmodel\\data\\ggds\\diffresele.txt";
	read(inputpath);
	priority_queue<edge> que;
	for (int i = 0; i < vec.size(); ++i)
	{
		priority_queue<edge> nownode;
		for (int j = i+1; j < vec.size(); ++j)
		{
			edge tmp;
			tmp.from = vec[i].num, tmp.to = vec[j].num;
			tmp.value = dis(vec[i], vec[j]);
			nownode.push(tmp);
		}
		for (int j = 0; !nownode.empty()&&j < MAX_EDGE; ++j)
		{
			que.push(nownode.top());
			nownode.pop();
		}
	}
	int kclass = MAX_CLASS;
	k_means(que, kclass);
	vector<int> tofind[4010];
	for (int i = 0; i < vec.size(); ++i)
	{
		tofind[find(vec[i].num)].push_back(vec[i].num);
	}
	vector<int> nowknow[4000];
	int num = 0;
	for (int i = 0; i < 4000; ++i)
	{
		if (tofind[i].size() != 0)
		{
			nowknow[num++] = tofind[i];
		}
	}
	ofstream out(outputpath);
	for (int i = 0; i < kclass; ++i)
	{
		out << "第" << i+1 << "类的书为如下编号:" << endl;
		for (int j = 0; j < nowknow[i].size(); ++j)
		{
			out <<nowknow[i][j] << endl;
		}
	}
	return 0;
}