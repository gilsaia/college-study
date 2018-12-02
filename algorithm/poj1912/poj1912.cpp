//凸包问题···因为一个愚蠢的错误···找了半个小时原因···
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
double EPS=1e-10;
#define pai 3.14159265358979323846
//double pai=acos(-1.0);
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
        return P(x+p.x,y+p.y);
    }
    P operator-(P p)
    {
        return P(x-p.x,y-p.y);
    }
    P operator*(int d)
    {
        return P(x*d,y*d);
    }
    bool operator<(const P&a)const
    {
        if(x!=a.x)
        {
            return x<a.x;
        }
        return y<a.y;
    }
    double dot(P p)
    {
        return x*p.x+y*p.y;
    }
    double det(P p)
    {
        return x*p.y-y*p.x;
    }
}castle[100020];
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
inline double normalize(double r)
{
	if (r < -pai / 2.0 + EPS) r += pai * 2;
	return r;
}
 
inline double atan2(const P& p)
{
	return normalize(atan2(p.y, p.x));
}
bool double_cmp(double x,double y)
{
    return x+EPS<y;
}
double dist(P p,P q)
{
    return (p-q).dot(p-q);
}
double as[100020];
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i)
    {
        scanf("%lf%lf",&castle[i].x,&castle[i].y);
    }
    vector<P> chs;
    int n=0;
    if(N>1)
    {
        chs=convex_hull(castle,N);
        n=chs.size();
        chs.push_back(chs[0]);
    }
    for(int i=0;i<n;++i)
    {
        as[i]=atan2(chs[i+1]-chs[i]);
    }
    sort(as,as+n,double_cmp);
    P p1,p2;
    while(~scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y))
    {
        if(N<2)
        {
            puts("GOOD");
            continue;
        }
        int i=upper_bound(as,as+n,atan2(p2-p1),double_cmp)-as;
        int j=upper_bound(as,as+n,atan2(p1-p2),double_cmp)-as;
        if((p2-p1).det(chs[i]-p1)*(p2-p1).det(chs[j]-p1)>-EPS)
        {
            puts("GOOD");
        }
        else
        {
            puts("BAD");
        }
    }
    return 0;
}