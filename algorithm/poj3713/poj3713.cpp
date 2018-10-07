//不知道为什么被归到网络流里···题意是求三联通的问题···大致思路是枚举如果去掉一个点及其相连边是否还能保证双联通，因为若有第三条通路一定会经过其中某个点所以通过枚举可以发现
//判断双联通的方法则是判断是否有割点，即去掉该点图会变成两个子图，若有这样的点则意味着两侧的点相互之间一定不是双联通的，因为一定会经过这一个共同的点所以不可
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int N,M,head[520],dfn[520],low[520],edgecnt,dfsclock,del,flag,root;
struct Edge
{
    int v,next;
}edge[42000];
void init()
{
    edgecnt=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
    edge[edgecnt].v=v;
    edge[edgecnt].next=head[u];
    head[u]=edgecnt++;
}
void dfs(int u,int fa)
{
    if(flag)
    {
        return;
    }
    int child=0;
    low[u]=dfn[u]=++dfsclock;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==fa||v==del)
        {
            continue;
        }
        if(!dfn[v])
        {
            ++child;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if((u==root&&child>1)||(u!=root&&low[v]>=dfn[u]))
            {
                flag=1;
            }
        }
        else
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
}
int main()
{
    while(scanf("%d%d",&N,&M),N&&M)
    {
        init();
        for(int i=0;i<M;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        flag=0;
        for(int i=0;i<N;++i)
        {
            del=i;
            dfsclock=0;
            memset(dfn,0,sizeof(dfn));
            root=0;
            if(del==0)
            {
                root=1;
            }
            dfn[del]=1;
            dfs(root,-1);
            for(int j=0;j<N;++j)
            {
                if(!dfn[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(flag)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}