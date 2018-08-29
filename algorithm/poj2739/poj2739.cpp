//尺取法样题···基本套个模板就好···
#include<stdio.h>
bool isprime[100000];
int prime[10000],size=0;
int main()
{
    isprime[0]=isprime[1]=1;
    for(int i=2;i<=10000;i++)
    {
        if(!isprime[i])
        {
            prime[size++]=i;
            for(int j=i+i;j<=10000;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
    int k;
    while(scanf("%d",&k))
    {
        if(k==0)
        {
            break;
        }
        int l=0,r=0,sum=0,cnt=0;
        for(;;)
        {
            while(r<size&&sum<k)
            {
                sum+=prime[r++];
            }
            if(sum<k)
            {
                break;
            }
            if(sum==k)
            {
                cnt++;
            }
            sum-=prime[l++];
            if(prime[l]>k)
            {
                break;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}