//快速幂模板题···但是还要判断是不是素数就很烦了··不过看数据给的素数不是很大
#include<stdio.h>
#include<math.h>
long long modpow(long long x,long long n)
{
    long long res=1,mod=n;
    while(n>0)
    {
        if(n&1)
        {
            res=res*x%mod;
        }
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
int isprime(long long x)
{
    long double temp=x;
    long long i,j,k=(int)sqrt(temp);
    if ((x==2)||(x==3))
    return 1;
    if (x==0)
    return 0;
    for (i=2;i<=k;i++)
    if (x%i==0)
    return 0;
    return 1;
}

int main()
{
    long long x,n;
    while(scanf("%lld%lld",&n,&x))
    {
        if(x==0&&n==0)
        {
            break;
        }
        long long temp=x;
        if(isprime(n))
        {
            printf("no\n");
        }
        else
        {
            if(temp==modpow(x,n))
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
    }
    return 0;
}