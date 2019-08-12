#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int MAXN=1020;
const int MAXM=20020;
int v[MAXM],w[MAXM],edgenext[MAXM],head[MAXN],e,cnt[MAXN],vis[MAXN],nodesize;//head初始化为-1，模拟邻接表
ll d[MAXN];
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
int main()
{
    int n,ml,md;
    scanf("%d%d%d",&n,&ml,&md);
    init(n);
    for(int i=0;i<ml;++i)
    {
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        addedge(u,v,d);
    }
    for(int i=0;i<md;++i)
    {
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        addedge(v,u,-d);
    }
    SPFA(1);
    if(d[n]==inf)
    {
        printf("-2\n");
    }
    else if(inv[n])
    {
        printf("-1\n");
    }
    else
    {
        printf("%lld\n",d[n]);
    }
    return 0;
}