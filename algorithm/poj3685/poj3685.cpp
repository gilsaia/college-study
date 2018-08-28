//一样是完全没找对思路···实际是用了两次二分查找···其中找的值对于i是单调递增的···这个确实没看出来···
#include<stdio.h>
const long long INF=1e12;
long long N,M;
long long call(long long i,long long j)
{
    return i*i+j*j+100000*(i-j)+i*j;
}
bool judge(long long d)
{
    long long j,l,r,mid=0,ans=0,sum=0;
    for(j=1;j<=N;j++)
    {
        l=0,r=N+1;
        while(r-l>1)
        {
            mid=(l+r)/2;
            if(call(mid,j)<d)
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        sum+=l;
    }
    return sum<M;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long l,r,ans,mid;
        scanf("%lld%lld",&N,&M);
        l=-1*INF,r=INF;
        while(r-l>1)
        {
            mid=(l+r)/2;
            if(judge(mid))
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        printf("%lld\n",l);
    }
    return 0;
}