#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=3000+100;
int head[maxn];
int mx[maxn],my[maxn];
int dx[maxn],dy[maxn];
int used[maxn];
struct Node{
   int x,y;
   int  s;
}e[maxn];
struct node{
   int x,y;
}pos[maxn];
struct edge{
    int u,v;
    int next;
}ee[maxn*maxn];
int cas,t,n,m,cnt,num,dis;
bool SearchP()
{
    queue<int>q;
    dis=0x3f3f3f3f;
    CLEAR(dx,-1);
    CLEAR(dy,-1);
    REPF(i,1,n)
      if(mx[i]==-1)
      {
          q.push(i);
          dx[i]=0;
      }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(dx[u]>dis) break;
        for(int i=head[u];i!=-1;i=ee[i].next)
        {
            int v=ee[i].v;
            if(dy[v]==-1)
            {
                dy[v]=dx[u]+1;
                if(my[v]==-1)  dis=dy[v];
                else
                {
                    dx[my[v]]=dy[v]+1;
                    q.push(my[v]);
                }
            }
        }
    }
    return dis!=0x3f3f3f3f;
}
bool dfs(int u)
{
    for(int i=head[u];i!=-1;i=ee[i].next)
    {
        int v=ee[i].v;
        if(!used[v]&&dy[v]==dx[u]+1)
        {
            used[v]=1;
            if(my[v]!=-1&&dy[v]==dis)  continue;
            if(my[v]==-1||dfs(my[v]))
            {
                my[v]=u;
                mx[u]=v;
                return true;
            }
        }
    }
    return  false;
}
void work()
{
    int res=0;
    CLEAR(mx,-1);
    CLEAR(my,-1);
    while(SearchP())
    {
        CLEAR(used,0);
        REPF(i,1,n)
          if(mx[i]==-1&&dfs(i))  res++;
    }
    printf("Scenario #%d:\n%d\n\n",++num,res);
}
bool ok(int i,int j)
{
    double d=sqrt((double)(e[i].x-pos[j].x)*(e[i].x-pos[j].x)+(double)(e[i].y-pos[j].y)*(e[i].y-pos[j].y));
    return d/e[i].s<=t;
}
void addedge(int u,int v)
{
    ee[cnt].u=u;ee[cnt].v=v;
    ee[cnt].next=head[u];
    head[u]=cnt++;
}