#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=60;
const int MAXM=3000;
vector<int> G[MAXN];
int indegree[MAXN],used[MAXN],nowstack[MAXN],stanum;
int sta[MAXN];
int dfs(int i)
{
    used[i]=1;
    if(nowstack[i])
    {
        return i;
    }
    for(int j=0;j<G[i].size();++j)
    {
        nowstack[i]=1;
        sta[stanum++]=G[i][j];
        int res=dfs(G[i][j]);
        if(res!=0)
        {
            return res;
        }
        --stanum;
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
    stanum=0;
    for(int i=1;i<=n;++i)
    {
        if(used[i]==0)
        {
            sta[stanum++]=i;
            cirstart=dfs(i);
            if(cirstart!=0)
            {
                break;
            }
            --stanum;
        }
    }
    int startnum=0;
    while(sta[startnum]!=cirstart)
    {
        ++startnum;
    }
    printf("NO\n%d",sta[startnum++]);
    while(startnum!=stanum)
    {
        printf(",%d",sta[startnum++]);
    }
    printf("\n");
    return 0;
}