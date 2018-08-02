//简单来说··就是看给的数有几个质数因子然后分别求组合数乘起来就完了··因为规模足够小甚至不用求模···直接硬求就好···
#include<iostream>
using namespace std;
int C[22][22];
void init()
{
    C[1][0]=1;
    C[1][1]=1;
    for(int i=2;i<=20;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}
bool isprime[1200000];
int prime[1000000];
void preprime()
{
    isprime[0]=isprime[1]=1;
    int end=0;
    for(int i=2;i<1200000;i++)
    {
        if(!isprime[i])
        {
            prime[end]=i;
            end++;
            for(int j=i+i;j<1200000;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
int main()
{
    int N;
    init();
    preprime();
    while(cin>>N)
    {
        int sum=0,num=0;
        int add[22];
        for(int i=0;i<22;i++)
        {
            add[i]=0;
        }
        for(int i=0;prime[i]<=N;i++)
        {
            bool pan=0;
            while(N%prime[i]==0)
            {
                sum++;
                add[num]++;
                N/=prime[i];
                pan=1;
            }
            if(pan)
            {
                num++;
            }
        }
        int ans=1;
        cout<<sum<<" ";
        for(int i=0;i<num;i++)
        {
            ans*=C[sum][add[i]];
            sum-=add[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}