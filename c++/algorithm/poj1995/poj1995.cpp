//快速幂模板题
#include<stdio.h>
long long modpow(long long x,long long n,long long m)
{
    long long res=1;
    while(n>0)
    {
        if(n&1)
        {
            res=res*x%m;
        }
        x=x*x%m;
        n>>=1;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m;
        scanf("%d",&m);
        int n;
        scanf("%d",&n);
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long x,y;
            scanf("%lld%lld",&x,&y);
            ans+=modpow(x,y,m);
            ans%=m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}