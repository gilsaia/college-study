#include <cstdio>  
#include <cstring>  
#include<cmath>
#include <algorithm>  
#define MAXN 1010  
#define MAXM 1000000+10  
double INF=1e10;
using namespace std;  
struct Edge  
{  
    int from, to;
    double cost;  
};  
Edge edge[MAXM];  
int pre[MAXN];//存储父节点  
int vis[MAXN];//标记作用  
int id[MAXN];//id[i]记录节点i所在环的编号  
double in[MAXN];//in[i]记录i入边中最小的权值  
double zhuliu(int root, int n, int m, Edge *edge)//root根 n点数 m边数  
{  
    double res = 0;
    int u, v;  
    while(1)  
    {  
        for(int i = 0; i < n; i++)  
            in[i] = INF;//初始化  
        for(int i = 0; i < m; i++)  
        {  
            Edge E = edge[i];  
            if(E.from != E.to && E.cost < in[E.to])  
            {  
                pre[E.to] = E.from;//记录前驱  
                in[E.to] = E.cost;//更新  
            }  
        }  
        for(int i = 0; i < n; i++)  
            if(i != root && in[i] == INF)  
                return -1;//有其他孤立点 则不存在最小树形图  
        //找有向环  
        int tn = 0;//记录当前查找中 环的总数  
        memset(id, -1, sizeof(id));  
        memset(vis, -1, sizeof(vis));  
        in[root] = 0;//根  
        for(int i = 0; i < n; i++)  
        {  
            res += in[i];//累加  
            v = i;  
            //找图中的有向环 三种情况会终止while循环  
            //1,直到出现带有同样标记的点说明成环  
            //2,节点已经属于其他环  
            //3,遍历到根  
            while(vis[v] != i && id[v] == -1 && v != root)  
            {  
                vis[v] = i;//标记  
                v = pre[v];//一直向上找  
            }  
            //因为找到某节点属于其他环  或者 遍历到根  说明当前没有找到有向环  
            if(v != root && id[v] == -1)//必须上述查找已经找到有向环  
            {  
                for(int u = pre[v]; u != v; u = pre[u])  
                    id[u] = tn;//记录节点所属的 环编号  
                id[v] = tn++;//记录节点所属的 环编号  环编号累加  
            }  
        }  
        if(tn == 0) break;//不存在有向环  
        //可能存在独立点  
        for(int i = 0; i < n; i++)  
            if(id[i] == -1)  
                id[i] = tn++;//环数累加  
        //对有向环缩点  和SCC缩点很像吧  
        for(int i = 0; i < m; i++)  
        {  
            v = edge[i].to;  
            edge[i].from = id[edge[i].from];  
            edge[i].to = id[edge[i].to];  
            //<u, v>有向边   
            //两点不在同一个环 u到v的距离为 边权cost - in[v]  
            if(edge[i].from != edge[i].to)  
                edge[i].cost -= in[v];//更新边权值 继续下一条边的判定  
        }  
        n = tn;//以环总数为下次操作的点数 继续执行上述操作 直到没有环  
        root = id[root];  
    }  
    return res;  
} 
struct point
{
    int x,y;
};
point node[MAXN];
double cal(point x,point y)
{
    return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&node[i].x,&node[i].y);
        }
        for(int i=0;i<m;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            --u,--v;
            edge[i].from=u,edge[i].to=v;
            edge[i].cost=sqrt(cal(node[u],node[v]));
        }
        double ans=zhuliu(0,n,m,edge);
        if(ans==-1)
        {
            printf("poor snoopy\n");
        }
        else
        {
            printf("%.2lf\n",ans);
        }
    }
    return 0;
}