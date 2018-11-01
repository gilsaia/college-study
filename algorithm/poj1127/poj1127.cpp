//几何问题加上并查集···
#include<cstdio>
#include<algorithm>
#include<cmath>
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
int multiply(P p1,P p2,P p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
bool isIntersect(P p1,P p2,P q1,P q2)
{
    if(max(p1.x,p2.x)<min(q1.x,q2.x)||max(q1.x,q2.x)<min(p1.x,p2.x)||max(p1.y,p2.y)<min(q1.y,q2.y)||max(q1.y,q2.y)<min(p1.y,p2.y))
        return 0;
    if(multiply(q1,q2,p1)*multiply(q1,q2,p2)<=0&&multiply(p1,p2,q1)*multiply(p1,p2,q2)<=0)
        return 1;
    else
        return 0;
}

bool on_seg(P p1,P p2,P q)
{
    return(p1-q).det(p2-q)==0&&(p1-q).dot(p2-q)<=0;
}
P intersection(P p1,P p2,P q1,P q2)
{
    return p1+(p2-p1)*((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}
int n;
int par[20];
P p[20],q[20];
void initial(int n)
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
    else
    {
        return par[x]=find(par[x]);
    }
}
void unite(int x,int y)
{
    int fx=find(x),fy=find(y);
    par[fx]=fy;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        initial(n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d%d%d",&p[i].x,&p[i].y,&q[i].x,&q[i].y);
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                /*if((p[i]-q[i]).det(p[j]-q[j])==0)
                {
                    if(on_seg(p[i],q[i],p[j])||on_seg(p[i],q[i],q[j])||on_seg(p[j],q[j],p[i])||on_seg(p[j],q[j],q[i]))
                    {
                        unite(i,j);
                    }
                }
                else
                {
                    P r=intersection(p[i],q[i],p[j],q[j]);
                    if(on_seg(p[i],q[i],r)&&on_seg(p[j],q[j],r))
                    {
                        unite(i,j);
                    }
                }*/
                if(isIntersect(p[i],q[i],p[j],q[j]))
                {
                    unite(i,j);
                }
            }
        }
        int a,b;
        while(scanf("%d%d",&a,&b),a&&b)
        {
            if(find(a)==find(b))
            {
                printf("CONNECTED\n");
            }
            else
            {
                printf("NOT CONNECTED\n");
            }
        }
    }
    return 0;
}