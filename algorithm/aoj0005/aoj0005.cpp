//最简单的求最小公约数和最大公倍数模板，不过int爆数据了··改long long就好··
#include<iostream>
using namespace std;
long long Gcd(long long a,long long b)
{
    if(b==0)
    {
        return a;
    }
    return Gcd(b,a%b);
}
long long Lcm(long long a,long long b,long long gcd)
{
    return a*b/gcd;
}
int main()
{
    long long a,b;
    while(cin>>a>>b)
    {
        long long gcd=Gcd(a,b);
        long long lcm=Lcm(a,b,gcd);
        cout<<gcd<<" "<<lcm<<endl;
    }
    return 0;
}