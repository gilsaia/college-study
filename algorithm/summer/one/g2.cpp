#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int MAX_V=100020;
const int INFVAL=100020;
struct edge{int to,cap,rev};
vector<edge> G[MAX_V];
bool used[MAX_V];
void add_edge(int from,int to,int cap)
{
    edge tmp;
    tmp.to=to,tmp.cap=cap,tmp.rev=G[to].size();
    G[from].push_back(tmp);
    tmp.to=from,tmp.cap=0,tmp.rev=G[from].size()-1;
    G[to].push_back(tmp);
}
int dfs(int v,int t,int f)
{
    if(v==t)
    {
        return f;
    }
    used[v]=true;
    for(int i=0;i<G[v].size();++i)
    {
        edge &e=G[v][i];
        if(!used[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    while(true)
    {
        memset(used,0,sizeof(used));
        int f=dfs(s,t,INFVAL);
        if(f==0)
        {
            return flow;
        }
        flow+=f;
    }
}
struct node
{
    int num,dif;
};
node diff[MAX_V];
bool cmp(node a,node b)
{
    return a.dif>b.dif;
}
int main()
{
    int N,Q;
    scanf("%d%d",&N,&Q);
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<N;++j)
        {
            scanf("%d",&diff[j].dif);
            diff[j].num=j+2;
        }
        sort(diff,diff+N,cmp);
        for(int j=0;j<N-1;++j)
        {
            add_edge(diff[j].num,diff[j+1].num,INFVAL);
        }
    }
    for(int i=0;i<N;++i)
    {
        add_edge(i+2,1,1);
    }
}