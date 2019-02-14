//求排列数的第一个非零位···第一次见到正经模运算的题啊···
#include<cstdio>
#include<algorithm>
using namespace std;
int find_prime(int n,int x)
{
    int res=0;
    while(n)
    {
        res+=n/x;
        n/=x;
    }
    return res;
}
int end_with(int n,int x)
{
    if(n==0)
    {
        return 0;
    }
    int res=0;
    while(n)
    {
        res+=n/10+(n%10>=x);
        n/=5;
    }
    return res;
}
int sum_end_with(int n,int x)
{
    if(n==0)
    {
        return 0;
    }
    return sum_end_with(n/2,x)+end_with(n,x);
}
int lastdigit[4][4]=
{
    6,2,4,8,
    1,3,9,7,
    1,7,9,3,
    1,9,1,9
};
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        m=n-m;
        int two=find_prime(n,2)-find_prime(m,2);
        int five=find_prime(n,5)-find_prime(m,5);
        int three=sum_end_with(n,3)-sum_end_with(m,3);
        int seven=sum_end_with(n,7)-sum_end_with(m,7);
        int nine=sum_end_with(n,9)-sum_end_with(m,9);
        if(two<five)
        {
            printf("5\n");
            continue;
        }
        int res=1;
        if(two>five)
        {
            res*=lastdigit[0][(two-five)%4];
        }
        res*=lastdigit[1][three%4];
        res*=lastdigit[2][seven%4];
        res*=lastdigit[3][nine%4];
        res%=10;
        printf("%d\n",res);
    }
    return 0;
}