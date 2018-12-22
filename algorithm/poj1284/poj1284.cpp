//这道题就是求的所谓“原根”的数目，求法是套两层欧拉函数，但因为第一层给的是奇素数，所以可以直接求n-1的欧拉函数值
#include<cstdio>
#include<algorithm>
using namespace std;
int euler_phi(int n)
{
    int res=n;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            res=res/i*(i-1);
            for(;n%i==0;n/=i);
        }
    }
    if(n!=1)
    {
        res=res/n*(n-1);
    }
    return res;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        printf("%d\n",euler_phi(n-1));
    }
    return 0;
}