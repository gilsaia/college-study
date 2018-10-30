//完全不知道自己错哪里了····思路倒是大概看懂了···先假设一个要求一个圣诞老人···然后看哪些能合并就合并···
#include <cstdio>
#include <cstring>
#include <vector>
 
using namespace std;
 
////////////////////////最大流开始//////////////////////////////////////
#define MAX_V 1000 * 2 + 16
int V;                 // 顶点数
vector<int> G[MAX_V];    // 图的邻接表
int match[MAX_V];      // 所匹配的顶点
bool used[MAX_V];      // DFS中用到的访问标记
 
// 向图中增加一条连接u和v的边
void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
 
// 通过DFS寻找增广路
bool dfs(int v)
{
	used[v] = true;
	for (vector<int>::iterator it = G[v].begin(); it != G[v].end(); ++it)
	{
		int u = *it, w = match[u];
		if (w < 0 || !used[w] && dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
 
	return false;
}
 
// 求解二分图的最大匹配
int bipartite_matching()
{
	int res = 0;
	memset(match, -1, sizeof(match));
	for (int v = 0; v < V; ++v)
	{
		if (match[v] < 0)
		{
			memset(used, 0, sizeof(used));
			if (dfs(v))
			{
				++res;
			}
		}
	}
 
	return res;
}
 
void clear()
{
	for (int i = 0; i < V; ++i)
	{
		G[i].clear();
	}
}
 
///////////////////////////////最大流结束/////////////////////////////////////
#define  MAX_N 100
#define  MAX_L 1000
#define  INF 0x3f3f3f3f
 
int distance_matrix[MAX_N][MAX_N];		// 两点间最短路
int p[MAX_L], t[MAX_L];					// 房间编号，时刻
 
bool update_min(int& v, const int& t)
{
	if (t < v)
	{
		v = t;
		return true;
	}
	return false;
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	int N, M, L;
	while (scanf("%d%d%d", &N, &M, &L) != EOF && N)
	{
		V = L * 2;
		clear();
		memset(distance_matrix, INF, sizeof(distance_matrix));
 
		for (int _ = 0; _ < M; ++_)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			distance_matrix[u][v] = distance_matrix[v][u] = d;
		}
 
		for (int i = 0; i < L; ++i)
		{
			scanf("%d%d", p + i, t + i);
		}
 
		// warshall_floyd 两点间最短路
		for (int k = 0; k < N; ++k) 
		{
			distance_matrix[k][k] = 0;
			for (int i = 0; i < N; ++i) 
			{
				for (int j = 0; j < N; ++j) 
				{
					update_min(distance_matrix[i][j], distance_matrix[i][k] + distance_matrix[k][j]);
				}
			}
		}
 
		for (int i = 0; i < L; ++i) 
		{
			for (int j = 0; j < L; ++j)  
			{
				if (i != j && t[i] + distance_matrix[p[i]][p[j]] <= t[j])
				{
					add_edge(2 * i, 2 * j + 1);	// 可以在i之后处理j，连一条边
				}
			}
		}
 
		printf("%d\n", L - bipartite_matching());
	}
	return 0;
}
/*#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int V;
const int INF=1e9;
vector<int> G[5500];
int match[5500];
bool used[5500];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();++i)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<V;++v)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int distanc[120][120],p[5500],t[5500];
int main()
{
    int N,M,L;
    while(scanf("%d%d%d",&N,&M,&L),N&&M&&L)
    {
        memset(distanc,INF,sizeof(distanc));
        V=2*L;
        for(int i=0;i<=2*L;++i)
        {
            G[i].clear();
        }
        for(int i=0;i<M;++i)
        {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            distanc[u][v]=distanc[v][u]=d;
        }
        for(int i=0;i<L;++i)
        {
            scanf("%d%d",&p[i],&t[i]);
        }
        for(int k=0;k<N;++k)
        {
            distanc[k][k]=0;
            for(int i=0;i<N;++i)
            {
                for(int j=0;j<N;++j)
                {
                    distanc[i][j]=min(distanc[i][j],distanc[i][k]+distanc[k][j]);
                }
            }
        }
        for(int i=0;i<L;++i)
        {
            for(int j=0;j<L;++j)
            {
                if(i!=j&&t[i]+distanc[p[i]][p[j]]<=t[j])
                {
                    add_edge(2*i,2*j+1);
                }
            }
        }
        printf("%d\n",L-bipartite_matching());
    }
}*/