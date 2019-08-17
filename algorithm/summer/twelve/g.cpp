#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
    int a,t;
};
bool cmp(node a,node b)
{
    return a.a>b.a;
}
node source[10020];
int n;
double work()
{
    double v=0;
    double s=0;
    for(int i=0;i<n;++i)
    {
        double t=source[i].t,a=source[i].a;
        s+=v*t+a*t*t/2;
        v+=a*t;
    }
    return s;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",&source[i].a,&source[i].t);
    }
    double sum1=work();
    sort(source,source+n,cmp);
    double sum2=work();
    printf("%.1lf\n",sum2-sum1);
    return 0;
}