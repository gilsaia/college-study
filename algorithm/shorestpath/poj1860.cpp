#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
struct edge{
    int u,v;//两个点 
    double c,r;    //权值 
    edge(int _u = 0, int _v = 0, double _c = 0,double _r=0): u(_u), v(_v), c(_c),r(_r) {}
};
double dis[maxn];//松弛更新数组
vector<edge>e;//用容器存边 
//如果存在从源点可达的权为负的回路。则 应为无法收敛而导致不能求出最短路径
int bellman_ford(int s,int n,double start)
{
    memset(dis,0,sizeof(dis));
    dis[s]=start;
    //最多做n-1次 
    for(int i=1;i<n;i++)
    {
        int flag=0;
        for(int j=0; j<int(e.size()); j++)
        {
            if(dis[e[j].v] < (dis[e[j].u] -e[j].c)* e[j].r)
            {
                dis[e[j].v] = (dis[e[j].u]-e[j].c) * e[j].r;
                flag=1;
            }
        }
        if(flag==0) return 1;//没有负权回路 
    }
    //有负权回路 
    for(int j=0; j < int(e.size()); j++)
    {
        if(dis[e[j].v] < (dis[e[j].u]-e[j].c) * e[j].r)
        return 0;
    }
    return 1;
}
int main()
{
    int N,M,S;
    double V;
    scanf("%d%d%d%lf",&N,&M,&S,&V);
    for(int i=0;i<M;++i)
    {
        edge tmp,inv;
        scanf("%d%d%lf%lf%lf%lf",&tmp.u,&tmp.v,&tmp.r,&tmp.c,&inv.r,&inv.c);
        inv.u=tmp.v,inv.v=tmp.u;
        e.push_back(tmp);
        e.push_back(inv);
    }
    int ans=bellman_ford(S,N,V);
    if(ans)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    return 0;
}