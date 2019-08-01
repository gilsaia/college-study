#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f;
int trade[55][55];
int mincost[55];
struct node
{
    int num,cost;
    bool operator<(const node &rhs) const
    {
        return cost>rhs.cost;
    }
};
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int x,y;
        scanf("%d%d",&x,&y);
        memset(trade,-1,sizeof(trade));
        memset(mincost,INF,sizeof(mincost));
        int a,b,c;
        scanf("%d",&a);
        while(a!=0)
        {
            scanf("%d%d",&b,&c);
            trade[a][b]=c,trade[b][a]=c;
            scanf("%d",&a);
        }
        node start;
        start.num=x,start.cost=0;
        mincost[x]=0;
        priority_queue<node> que;
        que.push(start);
        while(!que.empty())
        {
            node tmp=que.top();
            que.pop();
            if(tmp.num==y)
            {
                break;
            }
            for(int i=1;i<=n;++i)
            {
                if(trade[tmp.num][i]!=-1)
                {
                    if((tmp.cost+trade[tmp.num][i])<mincost[i])
                    {
                        mincost[i]=tmp.cost+trade[tmp.num][i];
                        node next;
                        next.num=i,next.cost=mincost[i];
                        que.push(next);
                    }
                }
            }
        }
        printf("%d\n",mincost[y]);
    }
    return 0;
}