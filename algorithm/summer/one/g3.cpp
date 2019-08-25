#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int dfn[100010],low[100010],scc[100010];
int dfn_index=0,scc_index=0;
int on_stack[100010];
int stack[100010];
int st=0;
vector<int> G[100010];
void tarjan(int u)
{
	dfn[u] = low[u] = ++dfn_index;
	on_stack[u] = 1; stack[st++] = u;
	for(int i = 0; i<G[u].size(); ++i)
	{
		int v = G[u][i];
		if(!dfn[v])
		{
			// 树边的情况
			tarjan(v);
			if(low[v] < low[u])
				low[u] = low[v];
		} else if(on_stack[v] && dfn[v] < low[u]) {
			// 横叉边或者反祖边的情况
			low[u] = dfn[v];
		}
	}

	if(low[u] == dfn[u])
	{
        int tmp=0;
		++scc_index;
		while(tmp != u)
		{
			tmp = stack[--st];
			scc[tmp] = scc_index;
			on_stack[tmp] = 0;
		}
	}
}
struct node
{
    int num,dif;
};
node diff[100010];
bool cmp(node a,node b)
{
    return a.dif>b.dif;
}
int main()
{
    int N,Q,starttor;
    scanf("%d%d",&N,&Q);
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<N;++j)
        {
            scanf("%d",&diff[j].dif);
            diff[j].num=j;
        }
        sort(diff,diff+N,cmp);
        for(int j=0;j<N-1;++j)
        {
            G[diff[j+1].num].push_back(diff[j].num);
        }
        starttor=diff[N-1].num;
    }
    tarjan(starttor);
    for(int i=0;i<Q;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        --tmp;
        if(scc[tmp]==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}