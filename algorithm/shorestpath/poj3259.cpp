#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
struct edge{
    int u,v;//两个点 
    int w;    //权值 
     edge(int _u = 0, int _v = 0, int _w = 0): u(_u), v(_v), w(_w) {}
};
int dis[maxn];//松弛更新数组
vector<edge>e;//用容器存边 
//如果存在从源点可达的权为负的回路。则 应为无法收敛而导致不能求出最短路径
int bellman_ford(int n)
{
    memset(dis,0,sizeof(dis));
    //最多做n-1次 
    for(int i=1;i<n;i++)
    {
        int flag=0;
        for(int j=0; j<int(e.size()); j++)
        {
            if(dis[e[j].v] > dis[e[j].u] + e[j].w)
            {
                dis[e[j].v] = dis[e[j].u] + e[j].w;
                flag=1;
            }
        }
        if(flag==0) return 1;//没有负权回路 
    }
    //有负权回路 
    for(int j=0; j < int(e.size()); j++)
    {
        if(dis[e[j].v] > dis[e[j].u] + e[j].w)
        return 0;
    }
    
    return 1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        e.clear();
        int N,M,W;
        scanf("%d%d%d",&N,&M,&W);
        for(int j=0;j<M;++j)
        {
            edge tmp;
            scanf("%d%d%d",&tmp.u,&tmp.v,&tmp.w);
            e.push_back(tmp);
            swap(tmp.u,tmp.v);
            e.push_back(tmp);
        }
        for(int j=0;j<W;++j)
        {
            edge tmp;
            scanf("%d%d%d",&tmp.u,&tmp.v,&tmp.w);
            tmp.w*=-1;
            e.push_back(tmp);
        }
        if(bellman_ford(N))
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}