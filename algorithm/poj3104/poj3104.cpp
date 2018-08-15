//二分判断问题···又是自己写的判断函数死活有问题···加了各自特判也不行···最后找的题解的···虽然能看懂但是还是不知道自己写的错在哪了··很糟心···
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
const long long INF=1e9+2;
long long N,K;
long long x[100010];
long long judge(long long t){           
    long long i,sum;                    
    sum=0;                             
    for(i=0;i<N;i++)                    
    if(x[i]>t)                          
    sum+=(long long)(ceil((x[i]-t)*1.0/(K-1)));
    return sum;
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    while(cin>>N)
    {
        long long maxm=0;
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&x[i]);
            maxm=max(maxm,x[i]);
        }
        sort(x,x+N,cmp);
        scanf("%lld",&K);
        long long lb=0,ub=maxm,ans;
        if(N==1)
        {
            long long temp=x[0]/K;
            if(x[0]%K!=0)
            {
                temp++;
            }
            printf("%lld\n",temp);
            continue;
        }
        if(K==1)
        {
            printf("%lld\n",maxm);
            continue;
        }
        while(lb<=ub)
        {
            long long mid=(lb+ub)/2;
            if(judge(mid)<=mid)
            {
                ans=mid;
                ub=mid-1;
            }
            else
            {
                lb=mid+1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}