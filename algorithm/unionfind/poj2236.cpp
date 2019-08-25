#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int par[1040];
void init(int n)
{
    for(int i=0;i<=n;++i)
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
}
struct point
{
    int x,y;
};
int cal(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
point cit[1020];
int main()
{
    vector<int> rep;
    int n,d;
    scanf("%d%d",&n,&d);
    init(n);
    d=d*d;
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&cit[i].x,&cit[i].y);
    }
    char op[2];
    while(~scanf("%s",op))
    {
        if(op[0]=='O')
        {
            int a;
            scanf("%d",&a);
            for(int i=0;i<rep.size();++i)
            {
                if(cal(cit[a],cit[rep[i]])<=d)
                {
                    unite(a,rep[i]);
                }
            }
            rep.push_back(a);
        }
        else
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(same(a,b))
            {
                printf("SUCCESS\n");
            }
            else
            {
                printf("FAIL\n");
            }
        }
    }
    return 0;
}