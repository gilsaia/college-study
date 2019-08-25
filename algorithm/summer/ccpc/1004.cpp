#include<cstdio>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
struct node
{
    int num;
    ll dis;
    bool operator<(const node &rhs) const
    {
        return dis>rhs.dis;
    }
};
vector<node> G[100020];
ll findmin[100020];
int findindex[100020];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;++i)
        {
            G[i].clear();
        }
        for(int i=0;i<m;++i)
        {
            int u;
            node tmp;
            scanf("%d%d%lld",&u,&tmp.num,&tmp.dis);
            G[u].push_back(tmp);
        }
        int maxindex=0;
        ll maxdis=0;
        for(int i=0;i<q;++i)
        {
            scanf("%d",&findindex[i]);
            maxindex=max(maxindex,findindex[i]);
        }
        priority_queue<node> que;
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<G[i].size();++j)
            {
                node tmp;
                tmp.num=G[i][j].num,tmp.dis=G[i][j].dis;
                que.push(tmp);
                maxdis=(maxdis,tmp.dis);
            }
        }
        for(int i=1;i<=maxindex;++i)
        {
            node tmp=que.top();
            que.pop();
            findmin[i]=tmp.dis;
            int u=tmp.num;
            for(int j=0;j<G[u].size();++j)
            {
                node next;
                next.num=G[u][j].num;
                next.dis=tmp.dis+G[u][j].dis;
                if((i+que.size())>=maxindex&&next.dis>maxdis)
                {
                    continue;
                }
                que.push(next);
                maxdis=max(maxdis,next.dis);
            }
        }
        for(int i=0;i<q;++i)
        {
            printf("%lld\n",findmin[findindex[i]]);
        }
    }
    return 0;
}