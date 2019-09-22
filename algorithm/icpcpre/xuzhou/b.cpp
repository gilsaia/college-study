#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int par[1000200];
int find(int x)
{
    if(x==par[x])
    {
        return par[x];
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
    par[y]=x;
}
int tofind[1000020][2];
int toreflec[1000020];
int main()
{
    map<int,int> reflec;
    int n,q,cnt=0;
    scanf("%d%d",&n,&q);
    for(int i=0;i<q;++i)
    {
        scanf("%d%d",&tofind[i][0],&tofind[i][1]);
        toreflec[cnt++]=tofind[i][1];
    }
    sort(toreflec,toreflec+cnt);
    cnt=unique(toreflec,toreflec+cnt)-toreflec;
    
}