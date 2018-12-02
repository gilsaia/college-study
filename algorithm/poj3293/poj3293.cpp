//计算几何问题···算相交的时候···暴力也算过了似乎···
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct point
{
    int x,y,num;
    point():x(0),y(0),num(0){}
    point(int xe,int ye,int nu):x(xe),y(ye),num(nu){}
};
struct line
{
    int x1,x2,y1,y2;
    line():x1(0),x2(0),y1(0),y2(0){}
    line(point a,point b):x1(a.x),y1(a.y),x2(b.x),y2(b.y){}
};
bool cmpx(point a,point b)
{
    if(a.x==b.x)
    {
        return a.y<b.y;
    }
    return a.x<b.x;
}
bool cmpy(point a,point b)
{
    if(a.y==b.y)
    {
        return a.x<b.x;
    }
    return a.y<b.y;
}
point pointer[100100];
vector<line> lines;
int par[100100];
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
    int a=find(x);
    int b=find(y);
    if(a==b)
    {
        return;
    }
    par[a]=b;
    return;
}
int n;
int solve()
{
    if(n&1==1)
    {
        return -1;
    }
    int res=0;
    sort(pointer,pointer+n,cmpx);
    for(int i=0;i<n;i+=2)
    {
        if(pointer[i].x!=pointer[i+1].x)
        {
            return -1;
        }
        line tmp(pointer[i],pointer[i+1]);
        lines.push_back(tmp);
        unite(pointer[i].num,pointer[i+1].num);
        res+=pointer[i+1].y-pointer[i].y;
    }
    sort(pointer,pointer+n,cmpy);
    for(int i=0;i<n;i+=2)
    {
        if(pointer[i].y!=pointer[i+1].y)
        {
            return -1;
        }
        int tmpy=pointer[i].y;
        for(int j=0;j<lines.size();++j)
        {
            if(tmpy>lines[j].y1&&tmpy<lines[j].y2&&lines[j].x1>pointer[i].x&&lines[j].x1<pointer[i+1].x)
            {
                return -1;
            }
        }
        unite(pointer[i].num,pointer[i+1].num);
        res+=pointer[i+1].x-pointer[i].x;
    }
    int root=find(0);
    for(int i=1;i<n;++i)
    {
        if(root!=find(i))
        {
            return -1;
        }
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&pointer[i].x,&pointer[i].y);
            pointer[i].num=i;
        }
        for(int i=0;i<n;++i)
        {
            par[i]=i;
        }
        lines.clear();
        ans=solve();
        printf("%d\n",ans);
    }
    return 0;
}