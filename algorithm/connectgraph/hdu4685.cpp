#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2000;
const int M=1000000+3000;
struct EDGE{
    int v,next;
}edge[M];
int first[N],low[N],dfn[N],sta[M],belong[N];
int ans[N],match[N],flag[N];
bool instack[N],vis[N];
int n,m,g,cnt,top,scc,maxn;
int Scan()      //输入外挂
{
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return flag?-res:res;
}
void Out(int a)    //输出外挂
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
void AddEdge(int u,int v)
{
    edge[g].v=v;
    edge[g].next=first[u];
    first[u]=g++;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
void init()
{
    g=cnt=top=scc=0;
    memset(first,-1,sizeof(first));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
    memset(flag,0,sizeof(flag));
    //scanf("%d%d",&n,&m);
    n=Scan();
    m=Scan();
    maxn=max(n,m);    //王子和公主数可能不同，为了建图方便去较大者，王子编号1--maxn,公主编号maxn+1--2*maxn
}
bool dfs(int u)
{
    int i,v;
    for(i=first[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!vis[v])
        {
            vis[v]=true;
            if(match[v]==0||dfs(match[v]))
            {
                match[v]=u;
                flag[u]=v;
                return true;
            }
        }
    }
    return false;
}
void xiong()    //二分匹配
{
    int i;
    memset(match,0,sizeof(match));
    for(i=1;i<=maxn;i++)
    {
        memset(vis,false,sizeof(vis));
        dfs(i);
    }
}
void Tarjan(int u)     //求强连通分量
{
    int i,v;
    low[u]=dfn[u]=++cnt;
    sta[++top]=u;
    instack[u]=true;
    for(i=first[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        scc++;
        while(1)
        {
            v=sta[top--];
            instack[v]=false;
            belong[v]=scc;
            if(u==v)
                break;
        }
    }
}
void build()
{
    int i,k,v,j;
    for(i=1;i<=n;i++)
    {
    //    scanf("%d",&k);
        k=Scan();
        while(k--)
        {
        //    scanf("%d",&v);
            v=Scan();
            AddEdge(i,v+maxn);    //王子和喜欢的公主之间连边
        }
    }

    xiong();   //做一次二分匹配

    int all=2*maxn;
    for(i=1;i<=maxn;i++)    //为剩余王子匹配虚拟公主
    {
        if(!flag[i])
        {
            all++;
            for(j=1;j<=maxn;j++)  //所有王子都喜欢该虚拟公主
                AddEdge(j,all);
            match[all]=i;
            flag[i]=all;
        }
    }

    for(i=maxn+1;i<=2*maxn;i++)    //为剩余公主匹配虚拟王子
    {
        if(!match[i])
        {
            all++;
            for(j=maxn+1;j<=2*maxn;j++)   //该虚拟王子喜欢所有公主
                AddEdge(all,j);
            flag[all]=i;
            match[i]=all;
        }
    }
    for(i=1;i<=all;i++)    //所有与王子匹配的公主建一条边连向王子
    {
        if(flag[i])
            AddEdge(flag[i],i);
    }
}
void solve()
{
    int i,u,v;
    for(i=1;i<=maxn;i++)   //求强连通分量
        if(!dfn[i])
            Tarjan(i);

    for(u=1;u<=n;u++)  //枚举所有王子
    {
        int count=0;
        for(i=first[u];i!=-1;i=edge[i].next)
        {
            v=edge[i].v;
            if(belong[u]==belong[v])    //王子与公主同在一个强连通分量
            {
                if(v-maxn>m)
                    continue;
                ans[count++]=v-maxn;
            }
        }
        sort(ans,ans+count);
    //    printf("%d",count);
        Out(count);
        for(i=0;i<count;i++)      //输出
        {
            //printf(" %d",ans[i]);
            putchar(' ');
            Out(ans[i]);
        }
    //    printf("\n");
        putchar('\n');
    }
}
int main()
{
    int t,cas;;
//    scanf("%d",&t);
    t=Scan();
    for(cas=1;cas<=t;cas++)
    {
        init();
        build();
        printf("Case #%d:\n",cas);
        solve();
    }
    return 0;
}