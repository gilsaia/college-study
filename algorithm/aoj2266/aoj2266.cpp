//算是最小费用流的问题····但是emmmmmmmm真心难···看了半天才看明白···
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include<utility>

using namespace std;
#define INF (1000000300)
typedef long long ll;
typedef pair<int,int> P;
const int MAXV=1e4+300;
int V;
const int s=MAXV-1,t=MAXV-2;
struct EDGE{
    int to,cap,cost,next;
}ES[MAXV*10];
int eh;
int h[MAXV];
int dis[MAXV];
int prevv[MAXV],preve[MAXV];
int head[MAXV];
void addedge(int from,int to,int cap,int cost){
    ES[eh].to=to;ES[eh].cap=cap;ES[eh].cost=cost;
    ES[eh].next=head[from];head[from]=eh++;
    ES[eh].to=from;ES[eh].cap=0;ES[eh].cost=-cost;
    ES[eh].next=head[to];head[to]=eh++;
}
bool inq[MAXV];
ll min_cost_flow(int s,int t,int f){
    V=MAXV;//default V size maxed
    ll res=0;
    memset(h,0,sizeof h);
    queue<P> Q;////spfa计算势h
    fill(dis,dis+V,INF);
    dis[s]=0;
    Q.push(P(0,s));
    inq[s]=1;
    while(!Q.empty()){
        P p=Q.front();Q.pop();
        int v=p.second;
        inq[v]=0;
        for(int i=head[v];i!=-1;i=ES[i].next){
            EDGE &e=ES[i];
            if(e.cap>0&&dis[e.to]>dis[v]+e.cost+h[v]-h[e.to]){
                dis[e.to]=dis[v]+e.cost +h[v]-h[e.to];
                prevv[e.to]=v;
                preve[e.to]=i;
                if(!inq[e.to]) Q.push(P(dis[e.to],e.to)),inq[e.to]=1;
            }
        }
    }
    for(int v=0;v<V;v++)
        h[v]+=dis[v];
    while(f>0){
        priority_queue<P,vector<P> ,greater<P> >Q;////Dijkstra计算势h
        fill(dis,dis+V,INF);
        dis[s]=0;
        Q.push(P(0,s));
        while(!Q.empty()){
            P p=Q.top();Q.pop();
            int v=p.second;
            if(dis[v]<p.first) continue;
            for(int i=head[v];i!=-1;i=ES[i].next){
                EDGE &e=ES[i];
                if(e.cap>0&&dis[e.to]>dis[v]+e.cost+h[v]-h[e.to]){
                    dis[e.to]=dis[v]+e.cost +h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    Q.push(P(dis[e.to],e.to));
                }
            }
        }
        if(dis[t]==INF) return -1;
        for(int v=0;v<V;v++) h[v]+=dis[v];
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
            d=min(d,ES[preve[v]].cap);
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v]){
            EDGE &e=ES[preve[v]];
            e.cap-=d;
            ES[preve[v]^1].cap+=d;
        }
    }
    return res;
}
void clear_G(){
    eh=0;
    memset(head,-1,sizeof head);
}

const int maxn=1e4+300;
int M,N,K;
int a[maxn],w[maxn];
int last[maxn];
int tol;
int hh;
void build(){
    for(int i=1;i<hh;i++){
        tol+=w[a[i]];
        if(last[a[i]])
            addedge(last[a[i]],i-1,1,-w[a[i]]);
        last[a[i]]=i;
    }
    for(int i=1;i<hh-1;i++)
        addedge(i,i+1,INF,0);
}
int main(){
    clear_G();
    scanf("%d%d%d",&M,&N,&K);
    for(int i=1;i<=N;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=K;i++)
        scanf("%d",&a[i]);
    hh=unique(a+1,a+K+1)-a;
    build();
    int ans=min_cost_flow(1,hh-1,M-1);
    printf("%d\n",tol+ans);
    return 0;    
}