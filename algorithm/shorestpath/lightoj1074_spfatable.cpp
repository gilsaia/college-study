#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN=220;
const int MAXM=40050;
int v[MAXM],w[MAXM],edgenext[MAXM],head[MAXN],d[MAXN],e,cnt[MAXN],vis[MAXN],nodesize;//head初始化为-1，模拟邻接表
int inv[MAXN];
void init(int n)
{
    memset(head,-1,sizeof(head));
    memset(cnt,0,sizeof(cnt));
    memset(d,inf,sizeof(d));
    memset(vis,0,sizeof(vis));
    memset(inv,0,sizeof(inv));
    e=0;
    nodesize=n;
}
void dfs(int t)
{
    inv[t]=1;
    for(int i=head[t];i!=-1;i=edgenext[i])
    {
        if(!inv[v[i]])
        {
            dfs(v[i]);
        }
    }
}
void addedge(int a,int b,int x)//主要如果是无向图的话,每条边要执行两次这个，a,b反过来就行
{
    v[e]=b;
    w[e]=x;
    edgenext[e]=head[a];
    head[a]=e++;
}
 
void SPFA(int s)
{
    queue<int> q;
    d[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        vis[u]=false;
        q.pop();
        for(int i=head[u]; i!=-1; i=edgenext[i])
        {
            if(inv[v[i]])
            {
                continue;
            }
            if(d[v[i]]>d[u]+w[i])
            {
                d[v[i]]=d[u]+w[i];
                if(!vis[v[i]])
                {
                    vis[v[i]]=true;
                    q.push(v[i]);
                    if(++cnt[v[i]]>=nodesize)
                    {
                        dfs(v[i]);
                    }
                }
            }
        }
    }
}
int val[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        int n;
        scanf("%d",&n);
        init(n);
        for(int j=1;j<=n;++j)
        {
            scanf("%d",&val[j]);
        }
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;++j)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            int dis=(val[v]-val[u])*(val[v]-val[u])*(val[v]-val[u]);
            addedge(u,v,dis);
        }
        SPFA(1);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",i);
        for(int j=0;j<q;++j)
        {
            int tmp;
            scanf("%d",&tmp);
            if(inv[tmp]||d[tmp]==inf||d[tmp]<3)
            {
                printf("?\n");
            }
            else
            {
                printf("%d\n",d[tmp]);
            }
        }
    }
    return 0;
}