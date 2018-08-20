//emmmmmmmm根据所给思路发现可以根据前两个推出第三个长度···所以二分第二个点的高度来确定···最后的答案判断非常迷···自己加了几个乱七八糟的居然就过了···
#include<stdio.h>
const double INF=1e13;
const double eps=1e-8;
double A,B,s[1030];
int N;
bool C(double x)
{
    s[2]=x;
    for(int i=3;i<=N;i++)
    {
        s[i]=s[i-1]*2-s[i-2]+2;
        if(s[i]<0)
        {
            return false;
        }
    }
    B=s[N];
    return true;
}
int main()
{
    scanf("%d%lf",&N,&A);
    s[1]=A;
    double lb=-1,ub=1011;
    for(int i=0;i<100;i++)
    {
        double mid=(lb+ub)/2;
        if(C(mid))
        {
            ub=mid;
        }
        else
        {
            lb=mid;
        }
    }
    printf("%.2f\n",B);
    return 0;
}