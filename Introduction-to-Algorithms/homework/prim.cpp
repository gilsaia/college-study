#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct edge 
{
    int to,value;
    bool operator<(const edge &a) const
    {
        return value>a.value;
    }
};
vector<edge> G[60];
bool used[60];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int u,v;
        edge tmp;
        scanf("%d%d%d",&u,&v,&tmp.value);
        tmp.to=v;
        G[u].push_back(tmp);
        tmp.to=u;
        G[v].push_back(tmp);
    }
    int ans=0;
    priority_queue<edge> que;
    for(int i=0;i<G[1].size();++i)
    {
        que.push(G[1][i]);
    }
    used[1]=true;
    while(!que.empty())
    {
        edge tmp=que.top();
        que.pop();
        if(!used[tmp.to])
        {
            used[tmp.to]=true;
            ans+=tmp.value;
            for(int i=0;i<G[tmp.to].size();++i)
            {
                que.push(G[tmp.to][i]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}