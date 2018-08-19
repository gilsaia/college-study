//还是题意理解很重要······emmmmmmmm最短路加二分解决···然而临界条件自己一直写不准···
#include<vector>
#include<stdio.h>
#include<queue>
#include<utility>
#include<functional>
using namespace std;
struct edge
{
    int to,cost,length;
};
typedef pair<int,int> P;
vector<edge> G[1010];
int d[1010],N;
const int INF=1e9;
void dijk(int s)
{
    priority_queue<P,vector<P>,greater<P>> que;
    fill(d,d+N+1,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first)
        {
            continue;
        }
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+ e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int C(int x)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            if(G[i][j].length<x)
            {
                G[i][j].cost=0;
            }
            else
            {
                G[i][j].cost=1;
            }
        }
    }
    dijk(1);
    return d[N];
}
int main()
{
    int p,k,lb=0,ub=INF+10;
    scanf("%d%d%d",&N,&p,&k);
    for(int i=0;i<p;i++)
    {
        int f,t;
        edge temp;
        scanf("%d%d%d",&f,&t,&temp.length);
        ub=max(ub,temp.length);
        temp.to=t;
        G[f].push_back(temp);
        temp.to=f;
        G[t].push_back(temp);
    }
    while(ub-lb>1)
    {
        int mid=(ub+lb)/2;
        if(C(mid)>k)
        {
            lb=mid;
        }
        else
        {
            ub=mid;
        }
    }
    if(lb>INF)
    {
        lb=-1;
    }
    printf("%d\n",lb);
    return 0;
}