//二分法里的最大化平均值···基本套模板就好了···
#include<stdio.h>
#include<algorithm>
using namespace std;
long long w[1020],v[1020];
double y[1020];
int N,K;
bool cmp(double a,double b)
{
    return a>b;
}
bool C(double x)
{
    for(int i=0;i<N;i++)
    {
        y[i]=v[i]-x*w[i];
    }
    sort(y,y+N,cmp);
    double sum=0;
    for(int i=0;i<K;i++)
    {
        sum+=y[i];
    }
    return sum>=0;
}
int main()
{
    while(scanf("%d%d",&N,&K))
    {
        if(N==0&&K==0)
        {
            break;
        }
        K=N-K;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&v[i]);
        }
        for(int i=0;i<N;i++)
        {
            scanf("%d",&w[i]);
        }
        double lb=0,ub=2;
        for(int i=0;i<15;i++)
        {
            double mid=(ub+lb)/2;
            if(C(mid))
            {
                lb=mid;
            }
            else
            {
                ub=mid;
            }
        }
        printf("%.0f\n",lb*100);
    }
    return 0;
}