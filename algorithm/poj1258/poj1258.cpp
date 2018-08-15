//最小生成树的模板题，我是用并查集的算法写的，似乎有点慢··
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct edge
{
    int u,v,cost;
};
bool cmp(edge a,edge b)
{
    return a.cost<b.cost;
}
edge dat[10010];
int par[120];
void init()
{
    for(int i=0;i<=100;i++)
    {
        par[i]=i;
    }
}
int find(int x)
{
    if(par[x]==x)
    {
        return x;
    }
    else
    {
        return par[x]=find(par[x]);
    }
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
    {
        return;
    }
    par[x]=y;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    int n;
    while(cin>>n)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int temp;
                scanf("%d",&temp);
                if(j>i)
                {
                    dat[num].u=i;
                    dat[num].v=j;
                    dat[num].cost=temp;
                    num++;
                }
            }
        }
        sort(dat,dat+num,cmp);
        init();
        int ans=0;
        for(int i=0;i<num;i++)
        {
            edge e=dat[i];
            if(!same(e.u,e.v))
            {
                unite(e.u,e.v);
                ans+=e.cost;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}