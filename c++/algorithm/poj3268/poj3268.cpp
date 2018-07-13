//单源最短路问题，题意里说的是有向路英文不好没太理解···
//问去和来总和的最大即将路反向一次即可··
#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>
#include<functional>
using namespace std;
struct edge
{
    int to,cost;
};
typedef pair<int,int> P;
const int INF=1e9;
vector<edge> S[1010],R[1010];
int star[1010],retu[1010];
int main()
{
    int N,M,X;
    scanf("%d%d%d",&N,&M,&X);
    for(int i=0;i<M;i++)
    {
        int from,to,cost;
        scanf("%d%d%d",&from,&to,&cost);
        edge temp;
        temp.to=to;
        temp.cost=cost;
        S[from].push_back(temp);
        temp.to=from;
        R[to].push_back(temp);
    }
    priority_queue<P,vector<P>,greater<P>> que1;
    for(int i=0;i<=N;i++)
    {
        star[i]=INF;
        retu[i]=INF;
    }
    star[X]=0;
    retu[X]=0;
    que1.push(P(0,X));
    while(!que1.empty())
    {
        P p=que1.top();
        que1.pop();
        int v=p.second;
        if(star[v]<p.first)
        {
            continue;
        }
        for(int i=0;i<S[v].size();i++)
        {
            edge e=S[v][i];
            if(star[e.to]>star[v]+e.cost)
            {
                star[e.to]=star[v]+e.cost;
                que1.push(P(star[e.to],e.to));
            }
        }
    }
    que1.push(P(0,X));
    while(!que1.empty())
    {
        P p=que1.top();
        que1.pop();
        int v=p.second;
        if(retu[v]<p.first)
        {
            continue;
        }
        for(int i=0;i<R[v].size();i++)
        {
            edge e=R[v][i];
            if(retu[e.to]>retu[v]+e.cost)
            {
                retu[e.to]=retu[v]+e.cost;
                que1.push(P(retu[e.to],e.to));
            }
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++)
    {
        int temp=star[i]+retu[i];
        ans=max(temp,ans);
    }
    printf("%d\n",ans);
    return 0;
}