#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct edge 
{
    int to,value;//存这条边的终点和长度
    bool operator<(const edge &a) const//重载运算符以实现最小堆
    {
        return value>a.value;
    }
};
vector<edge> G[60];//每个点存储以该点为起点的边的数组
bool used[60];//存储相应的点是否在以计算过的集合中
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int u,v;
        edge tmp;
        scanf("%d%d%d",&u,&v,&tmp.value);//因为无向边，所以两侧都需存储一遍
        tmp.to=v;
        G[u].push_back(tmp);
        tmp.to=u;
        G[v].push_back(tmp);
    }
    int ans=0;
    priority_queue<edge> que;//建立最小堆
    for(int i=0;i<G[1].size();++i)//以1号点为起点将连接已考虑和未考虑的点集合的边加入队列
    {
        que.push(G[1][i]);
    }
    used[1]=true;//1号点已被考虑
    while(!que.empty())//当前还有边等待考虑时（可以将条件更改成计算已被考虑点的数目，为n时跳出，这样不需考虑所有的边，能够提高效率）
    {
        edge tmp=que.top();//取出当前最小边
        que.pop();
        if(!used[tmp.to])//如果这条边已经不是连接已考虑与未考虑点集合的边则跳过
        {
            used[tmp.to]=true;//将连接的点加入已考虑的集合
            ans+=tmp.value;//生成树值加上相应值
            for(int i=0;i<G[tmp.to].size();++i)//从当前考虑的点出发的所有边加入队列
            {
                que.push(G[tmp.to][i]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}