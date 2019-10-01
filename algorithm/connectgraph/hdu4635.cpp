
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n,m;
vector<int> G[maxn];
stack<int> S;
int dfs_clock, scc_cnt;
int pre[maxn],sccno[maxn],low[maxn];
int num[maxn];//分量的点数目
int out[maxn],in[maxn];
void dfs(int u)
{
    pre[u]=low[u]=++dfs_clock;
    S.push(u);
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!pre[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!sccno[v])
            low[u]=min(low[u],pre[v]);
    }
    if(low[u]==pre[u])
    {
        scc_cnt++;
        num[scc_cnt]=0;
        while(true)
        {
            int x=S.top(); S.pop();
            sccno[x]=scc_cnt;
            num[scc_cnt]++;
            if(x==u) break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock=scc_cnt=0;
    memset(pre,0,sizeof(pre));
    memset(sccno,0,sizeof(sccno));
    for(int i=1;i<=n;i++)
        if(!pre[i]) dfs(i);
}
int main()
{
    int T; scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        find_scc(n);
 
        for(int i=1;i<=scc_cnt;i++) in[i]=out[i]=0;
        for(int u=1;u<=n;u++)
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            int x=sccno[u], y=sccno[v];
            if(x==y) continue;
            in[y]++;
            out[x]++;
        }
        long long ans=0;
        int min_v=1e8;
        for(int i=1;i<=scc_cnt;i++)if(out[i]==0 || in[i]==0)
            min_v=min(min_v,num[i]);
        ans=(long long)n*n-n-(long long)min_v*(n-min_v)-m;
        printf("Case %d: %d\n",kase, scc_cnt==1?-1:ans);
    }
    return 0;
}