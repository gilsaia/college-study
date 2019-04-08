#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=60;
const int MAXM=3000;
vector<int> G[MAXN];
int indegree[MAXN],used[MAXN],nowstack[MAXN];

int dfs(int i,queue<int> &que)
{
    used[i]=1;
    if(nowstack[i])
    {
        return i;
    }
    for(int j=0;j<G[i].size();++j)
    {
        nowstack[i]=1;
        que.push(G[i][j]);
        int res=dfs(G[i][j],que);
        if(res!=0)
        {
            return res;
        }
        que.pop();
        nowstack[i]=0;
    }
    return 0;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    bool isselfcir=false;
    int selfcir;
    for(int i=0;i<m;++i)
    {
        int from,to;
        scanf("%d%d",&from,&to);
        if(from==to)
        {
            isselfcir=true;
            selfcir=from;
            continue;
        }
        ++indegree[to];
        G[from].push_back(to);
    }
    if(n==0)
    {
        printf("YES\n");
        return 0;
    }
    if(isselfcir)
    {
        printf("NO\n%d,%d\n",selfcir,selfcir);
        return 0;
    }
    queue<int> ans,nexttodo;
    for(int i=1;i<=n;++i)
    {
        if(indegree[i]==0)
        {
            nexttodo.push(i);
        }
    }
    int ansnum=0;
    while(!nexttodo.empty())
    {
        int now=nexttodo.front();
        nexttodo.pop();
        ans.push(now);
        ++ansnum;
        for(int i=0;i<G[now].size();++i)
        {
            --indegree[G[now][i]];
            if(indegree[G[now][i]]==0)
            {
                nexttodo.push(G[now][i]);
            }
        }
    }
    if(ansnum==n)
    {
        printf("YES\n%d",ans.front());
        ans.pop();
        while(!ans.empty())
        {
            printf(",%d",ans.front());
            ans.pop();
        }
        printf("\n");
        return 0;
    }
    int cirstart=0;
    queue<int> que;
    for(int i=1;i<=n;++i)
    {
        if(used[i]==0)
        {
            que.push(i);
            cirstart=dfs(i,que);
            if(cirstart!=0)
            {
                break;
            }
            que.pop();
        }
    }
    while(que.front()!=cirstart)
    {
        que.pop();
    }
    printf("NO\n%d",que.front());
    que.pop();
    while(!que.empty())
    {
        printf(",%d",que.front());
        que.pop();
    }
    printf("\n");
    return 0;
}