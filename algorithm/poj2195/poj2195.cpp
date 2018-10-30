//一样是最小费用流的问题···还是建好图一切都很好说了···
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<functional>
#include<cmath>
using namespace std;
const int INF=1e9;
typedef pair<int,int> P;
struct edge
{
    int to,cap,cost,rev;
};
int V;
vector<edge> G[505];
int h[505];
int dist[505];
int prevv[505],preve[505];
void add_edge(int from,int to,int cap,int cost)
{
    edge tmp;
    tmp.to=to,tmp.cap=cap,tmp.cost=cost,tmp.rev=G[to].size();
    G[from].push_back(tmp);
    tmp.to=from,tmp.cap=0,tmp.cost=-cost,tmp.rev=G[from].size()-1;
    G[to].push_back(tmp);
}
int min_cost_flow(int s,int t,int f)
{
    int res=0;
    fill(h,h+V,0);
    while(f>0)
    {
        priority_queue<P,vector<P>,greater<P>> que;
        fill(dist,dist+V,INF);
        dist[s]=0;
        que.push(P(0,s));
        while(!que.empty())
        {
            P p=que.top();
            que.pop();
            int v=p.second;
            if(dist[v]<p.first)
            {
                continue;
            }
            for(int i=0;i<G[v].size();++i)
            {
                edge &e=G[v][i];
                if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
                {
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t]==INF)
        {
            return -1;
        }
        for(int v=0;v<V;++v)
        {
            h[v]+=dist[v];
        }
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
int N,M;
char map[120][120];
int housex[120],housey[120],humanx[120],humany[120];
int main()
{
    while(scanf("%d%d",&N,&M),N||M)
    {
        for(int i=0;i<N;++i)
        {
            scanf("%s",map[i]);
        }
        int housenum=0,personnum=0;
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<M;++j)
            {
                if(map[i][j]=='H')
                {
                    housex[housenum]=i,housey[housenum++]=j;
                }
                else if(map[i][j]=='m')
                {
                    humanx[personnum]=i,humany[personnum++]=j;
                }
            }
        }
        int n=housenum,s=n*2,t=s+1;
        V=t+1;
        for(int i=0;i<=V;++i)
        {
            G[i].clear();
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                add_edge(j+n,i,1,abs(humanx[j]-housex[i])+abs(humany[j]-housey[i]));
            }
            add_edge(s,i+n,1,0);
            add_edge(i,t,1,0);
        }
        printf("%d\n",min_cost_flow(s,t,n));
    }
    return 0;
}