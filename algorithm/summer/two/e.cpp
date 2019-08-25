#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int par[20060],nodesize[20060];
void init(int n)
{
    for(int i=0;i<=n;++i)
    {
        par[i]=i;
        nodesize[i]=1;
    }
}
int find(int x)
{
    if(x==par[x])
    {
        return x;
    }
    return par[x]=find(par[x]);
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    par[x]=y;
    nodesize[y]+=nodesize[x];
}
int res[100020];
struct edge
{
    int x,y;
    int time;
    bool operator<(const edge &rhs) const
    {
        return time<rhs.time;
    }
};
bool cmp(edge a,edge b)
{
    return a.time<b.time;
}
edge road[100020];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        init(n);
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&road[i].x,&road[i].y,&road[i].time);
        }
        sort(road,road+m,cmp);
        res[0]=0;
        for(int i=0;i<m;++i)
        {
            int x=road[i].x,y=road[i].y;
            if(same(x,y))
            {
                continue;
            }
            int sizx=nodesize[find(x)],sizy=nodesize[find(y)];
            res[i]+=(sizx*sizy*2);
            unite(x,y);
            res[i+1]=res[i];
        }
        for(int i=0;i<q;++i)
        {
            int tmptime;
            scanf("%d",&tmptime);
            edge tmp;
            tmp.time=tmptime;
            int tofind=upper_bound(road,road+m,tmp)-road-1;
            printf("%d\n",res[tofind]);
        }
    }
    return 0;
}