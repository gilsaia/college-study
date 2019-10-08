#include<cstdio>
using namespace std;
unsigned int gcd(unsigned int a,unsigned int b){
    return b?gcd(b,a%b):a;
}
unsigned int modexp(unsigned int a,unsigned int b,unsigned int mod)
{
    unsigned int res=1;
    while(b>0)
    {
        if(b&1)
            res=res*a%mod;
        b=b/2;
        a=a*a%mod;
    }
    return res;
}
int main()
{
    printf("0-gcd，1-快速幂\n");
    unsigned int op;
    scanf("%u",&op);
    unsigned int res;
    if(op==0)
    {
        printf("输入a,b输出gcd(a,b)\n");
        unsigned int a,b;
        scanf("%u%u",&a,&b);
        res=gcd(a,b);
    }
    else
    {
        printf("输入x,y,p输出x^y mod p\n");
        unsigned int x,y,p;
        scanf("%u%u%u",&x,&y,&p);
        res=modexp(x,y,p);
    }
    printf("%u\n",res);
    return 0;
}