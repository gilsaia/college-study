#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
const int N=40;
const int INF=1e9+10;
const int INFVAL=1e5+10;
typedef pair<int, int>P;//first保存最短距离，second保存顶点的编号
 
struct Edge
{
	int to, cap, cost, rev;//终点，容量（指残量网络中的），费用，反向边编号
	Edge(int t, int c, int cc, int r) :to(t), cap(c), cost(cc), rev(r){}
};
int V;//顶点数
vector<Edge>G[N];//图的邻接表
int h[N];//顶点的势
int dist[N];//最短距离
int prevv[N];//最短路中的父结点
int preve[N];//最短路中的父边
 
void addedge(int from, int to, int cap, int cost)
{
	G[from].push_back(Edge( to, cap, cost, G[to].size()));
	G[to].push_back(Edge( from, 0, -cost, G[from].size() - 1 ));
}
int min_cost_flow(int s, int t, int f)//返回最小费用
{
	int res = 0;
	fill(h, h + V, 0);
	while (f>0)//f>0时还需要继续增广
	{
		priority_queue<P, vector<P>, greater<P> >q;
		fill(dist, dist + V, INF);//距离初始化为INF
		dist[s] = 0;
		q.push(P(0, s));
		while (!q.empty())
		{
			P p = q.top(); q.pop();
			int v = p.second;
			if (dist[v]<p.first)continue;//p.first是v入队列时候的值，dist[v]是目前的值，如果目前的更优，扔掉旧值
			for (int i = 0; i<G[v].size(); i++)
			{
				Edge&e = G[v][i];
				if (e.cap>0 && dist[e.to]>dist[v] + e.cost + h[v] - h[e.to])//松弛操作
				{
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					prevv[e.to] = v;//更新父结点
					preve[e.to] = i;//更新父边编号
					q.push(P(dist[e.to], e.to));
				}
			}
		}
		if (dist[t] == INF)//如果dist[t]还是初始时候的INF，那么说明s-t不连通，不能再增广了
			return -1;
		for (int j = 0; j<V; j++)//更新h
			h[j] += dist[j];
		int d = f;
		for (int x = t; x != s; x = prevv[x])
			d = min(d, G[prevv[x]][preve[x]].cap);//从t出发沿着最短路返回s找可改进量
		f -= d;
		res += d*h[t];//h[t]表示最短距离的同时，也代表了这条最短路上的费用之和，乘以流量d即可得到本次增广所需的费用
		for (int x = t; x != s; x = prevv[x])
		{
			Edge&e = G[prevv[x]][preve[x]];
			e.cap -= d;//修改残量值
			G[x][e.rev].cap += d;
		}
	}
	return res;
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<string,int> findnum;
    for(int i=0;i<n;++i)
    {
        string tmp;
        cin>>tmp;
        findnum[tmp]=i+2;
    }
    for(int i=0;i<m;++i)
    {
        int v;
        string a,b;
        cin>>a>>b>>v;
        addedge(findnum[a],findnum[b],INFVAL,v);
        addedge(findnum[b],findnum[a],INFVAL,v);
    }
}