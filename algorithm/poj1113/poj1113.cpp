//凸包的基本问题···就是找到凸多边形之后周长加上一个它要求的距离的圆周长即可···注意四舍五入问题（解决方法最后强制转换时加0.5）
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
double EPS=1e-10;
double pai=acos(-1.0);
double add(double a,double b)
{
    if(abs(a+b)<EPS*(abs(a)+abs(b)))
    {
        return 0;
    }
    return a+b;
}
struct P
{
    double x,y;
    P(){}
    P(double xe,double ye):x(xe),y(ye){}
    P operator +(P p)
    {
        return P(add(x,p.x),add(y,p.y));
    }
    P operator-(P p)
    {
        return P(add(x,-p.x),add(y,-p.y));
    }
    P operator*(int d)
    {
        return P(x*d,y*d);
    }
    int dot(P p)
    {
        return add(x*p.x,y*p.y);
    }
    int det(P p)
    {
        return add(x*p.y,-y*p.x);
    }
}castle[1020];
bool cmp_x(P &p,P &q)
{
    if(p.x!=q.x)
    {
        return p.x<q.x;
    }
    return p.y<q.y;
}
vector<P> convex_hull(P *ps,int n)
{
    sort(ps,ps+n,cmp_x);
    int k=0;
    vector<P> qs(n*2);
    for(int i=0;i<n;++i)
    {
        while(k>1&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0)
        {
            --k;
        }
        qs[k++]=ps[i];
    }
    for(int i=n-2,t=k;i>=0;--i)
    {
        while(k>t&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0)
        {
            --k;
        }
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}
double dist(P p,P q)
{
    return (p-q).dot(p-q);
}
int main()
{
    int N;
    double L;
    scanf("%d%lf",&N,&L);
    for(int i=0;i<N;++i)
    {
        scanf("%lf%lf",&castle[i].x,&castle[i].y);
    }
    vector<P> bag=convex_hull(castle,N);
    int size=bag.size();
    double dis=0;
    for(int i=0;i<size;++i)
    {
        dis+=sqrt(dist(bag[i],bag[(i+1)%size]));
    }
    int ans=(int)(dis+2*pai*L+0.5);
    printf("%d\n",ans);
    return 0;
}