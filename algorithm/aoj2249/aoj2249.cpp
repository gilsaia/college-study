//依旧是单源最短路问题，只要额外加一组表示花费的数组并且每次更新道路时每个节点最近被用的路的花费即可，哦对了还要加一个当距离一样是哪条路花费较少的判断
#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>
#include<functional>
using namespace std;
struct edge
{
    int to,cost,money;
};
vector<edge> G[10010];
int d[10010],m[10010];
const int INF=1e9;
typedef pair<int,int> P;
int main()
{
    int N,M;
    while(scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0)
        {
            break;
        }
        for(int i=0;i<=N;i++)
        {
            d[i]=INF;
            m[i]=INF;
            G[i].clear();
        }
        d[1]=0;
        m[1]=0;
        for(int i=0;i<M;i++)
        {
            edge temp;
            int x;
            scanf("%d%d%d%d",&x,&temp.to,&temp.cost,&temp.money);
            G[x].push_back(temp);
            int y=temp.to;
            temp.to=x;
            G[y].push_back(temp);
        }
        priority_queue<P,vector<P>,greater<P>> que;
        que.push(P(0,1));
        while(!que.empty())
        {
            P p=que.top();
            que.pop();
            int v=p.second;
            if(d[v]<p.first)
            {
                continue;
            }
            for(int i=0;i<G[v].size();i++)
            {
                edge e=G[v][i];
                if(d[e.to]>=d[v]+e.cost)
                {
                    if(d[e.to]==d[v]+e.cost)
                    {
                        m[e.to]=min(m[e.to],e.money);
                    }
                    else
                    {
                        d[e.to]=d[v]+e.cost;
                        que.push(P(d[e.to],e.to));
                        m[e.to]=e.money;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            ans+=m[i];
        }
        printf("%d\n",ans);
    }    
    return 0;
}