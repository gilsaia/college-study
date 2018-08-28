//二分题里最大化平均值的题···一个是这个算法速度会比较慢···还有一个精度要控制···排序一开始把函数写外面了会超时···写成成员函数一下就快了很多···
#include<stdio.h>
#include<algorithm>
using namespace std;
struct point
{
    int pos;
    double y;
    bool operator < (const point& rhs) const 
    {
        return y > rhs.y;
    }
};
bool cmp(point a,point b)
{
    return a.y>b.y;
}
point Y[100010];
int v[100010],w[100010];
int N,K;
const double INF=1e7;
bool C(double x)
{
    for(int i=0;i<N;i++)
    {
        Y[i].y=v[i]-x*w[i];
        Y[i].pos=i+1;
    }
    sort(Y,Y+N);
    double sum=0;
    for(int i=0;i<K;i++)
    {
        sum+=Y[i].y;
    }
    return sum>=0;
}
int main()
{
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&v[i],&w[i]);
    }
    double lb=0,ub=INF;
    for(int i=0;i<50;i++)
    {
        double mid=(lb+ub)/2;
        if(C(mid))
        {
            lb=mid;
        }
        else
        {
            ub=mid;
        }
    }
    for(int i=0;i<K-1;i++)
    {
        printf("%d ",Y[i].pos);
    }
    printf("%d",Y[K-1].pos);
    printf("\n");
    return 0;
}