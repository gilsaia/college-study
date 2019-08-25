#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
struct edge
{
    int to,cost;
};
struct node
{
    int condition,cost,viewcity,nowcity;
    bool operator<(const node &rhs) const
    {
        return cost>rhs.cost;
    }
};
bool view[1200200];
vector<edge> G[15];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(view,0,sizeof(view));
        for(int i=0;i<m;++i)
        {
            int from,to,cost;
            scanf("%d%d%d",&from,&to,&cost);
            --to,--from;
            edge tmp;
            tmp.cost=cost,tmp.to=to;
            G[from].push_back(tmp);
            tmp.to=from;
            G[to].push_back(tmp);
        }
        priority_queue<node> que;
        for(int i=0;i<n;++i)
        {
            node start;
            start.condition=0;
            start.condition|=(1<<(i*2));
            // view[start.condition]=true;
            start.viewcity=1;
            start.cost=0;
            start.nowcity=i;
            que.push(start);
        }
        int ans=-1;
        while(!que.empty())
        {
            node tmp=que.top();
            que.pop();
            if(tmp.viewcity==n)
            {
                ans=tmp.cost;
                break;
            }
            int from=tmp.nowcity;
            for(int i=0;i<G[from].size();++i)
            {
                int to=G[from][i].to;
                if((tmp.condition>>(to*2))&1)
                {
                    if(tmp.condition>>(to*2+1)&1)
                    {
                        continue;
                    }
                    node next=tmp;
                    next.nowcity=to;
                    next.cost+=G[from][i].cost;
                    next.condition|=(1<<(to*2+1));
                    // if(view[next.condition])
                    // {
                    //     continue;
                    // }
                    // view[next.condition]=true;
                    que.push(next);
                }
                else
                {
                    node next=tmp;
                    next.viewcity++;
                    next.nowcity=to;
                    next.cost+=G[from][i].cost;
                    next.condition|=(1<<(to*2));
                    // if(view[next.condition])
                    // {
                    //     continue;
                    // }
                    // view[next.condition]=true;
                    que.push(next);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}