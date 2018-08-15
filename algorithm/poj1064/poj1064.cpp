//二分查找例题，注意二分次数即可，另外这个转换思想不太好想
#include<stdio.h>
#include<math.h>
const int INF=1e9;
int N,K;
double L[10010];
bool C(double x)
{
    int num=0;
    for(int i=0;i<N;i++)
    {
        num+=(int)(L[i]/x);
    }
    return num>=K;
}
int main()
{
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
    {
        scanf("%lf",&L[i]);
    }
    double lb=0,ub=INF;
    for(int i=0;i<=100;i++)
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
    printf("%.2f\n",floor(ub*100)/100);
    return 0;
}