//计算几何里的凸包例题···emmmmmmmm大概能明白这个是啥意思了···
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
double EPS=1e-10;
int add(int a,int b)
{
    return a+b;
}
struct P
{
    int x,y;
    P(){}
    P(int xe,int ye):x(xe),y(ye){}
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
};
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
    scanf("%d",&N);
    P point[50030];
    for(int i=0;i<N;++i)
    {
        scanf("%d%d",&point[i].x,&point[i].y);
    }
    vector<P> qs=convex_hull(point,N);
    int n=qs.size();
    if(n==2)
    {
        printf("%.0f\n",dist(qs[0],qs[1]));
        return 0;
    }
    int i=0,j=0;
    for(int k=0;k<n;++k)
    {
        if(!cmp_x(qs[i],qs[k]))
        {
            i=k;
        }
        if(cmp_x(qs[j],qs[k]))
        {
            j=k;
        }
    }
    double res=0;
    int si=i,sj=j;
    while(i!=sj||j!=si)
    {
        res=max(res,dist(qs[i],qs[j]));
        if((qs[(i+1)%n]-qs[i]).det(qs[(j+1)%n]-qs[j])<0)
        {
            i=(i+1)%n;
        }
        else
        {
            j=(j+1)%n;
        }
    }
    printf("%.0f\n",res);
    return 0;
}