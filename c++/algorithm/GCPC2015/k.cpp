//快速判断素数的方法··抄的网上的模板叫米勒拉宾素数判断
#include<stdio.h>
#include<math.h>
#include<algorithm>
#define ll long long
using namespace std;

ll add_mod(ll a,ll b,ll mod){    //快乘法 基于快速幂的二分思想 
    ll ans=0;                    //由于考虑到取模数很大 快速幂会溢出 
    while(b){                    //必须使用该方法 
        if(b&1)                    //我这里写的是非递归版 
            ans=(ans+a)%mod;
        a=a*2%mod;
        b>>=1;
    }
    return ans;
}

ll pow_mod(ll a,ll n,ll mod){            //快速幂 递归版 
    if(n>1){                            
        ll tmp=pow_mod(a,n>>1,mod)%mod;
        tmp=add_mod(tmp,tmp,mod);
        if(n&1) tmp=add_mod(tmp,a,mod);
        return tmp;
    }
    return a;
}

bool Miller_Rabbin(ll n,ll a){//米勒拉宾素数判断函数主体
    ll d=n-1,s=0,i;    
    while(!(d&1)){            // 先把(2^s)*d 算出来 
        d>>=1;
        s++;
    }
    ll t=pow_mod(a,d,n);    //a^d取一次余判断 
    if(t==1 || t==-1)        //一或负一则可以声明这可能是质数 
        return 1;
    for(i=0;i<s;i++){                //不是的话继续乘上s个2 
        if(t==n-1)            //(n-1)*(n-1)%n=1 这一步是优化 
            return 1;
        t=add_mod(t,t,n);    // 快乘 
    }
    return 0;
}

bool is_prime(ll n){
    ll i,tab[4]={3,4,7,11};//本来应该取[1,n]内任意整数 
    for(i=0;i<4;i++){                //但一般这几个数足以,不需要太多组测试 
        if(n==tab[i])
            return 1;        //小判断小优化~ 
        if(!n%tab[i])
            return 0;
        if(n>tab[i] && !Miller_Rabbin(n,tab[i]))
            return 0;
    }
    return 1;
}
int wei[20];
bool prime(long long a)
{
    if(a==1)
    {
        return false;
    }
    if(a==2)
    {
        return true;
    }
    if(a%2==0)
    {
        return false;
    }
    if(is_prime(a))
    {
        return true;
    }
    else 
    {
        return false;
    }
}
int convert(int t)
{
    switch(t)
    {
        case 6:
        t=9;
        break;
        case 9:
        t=6;
        break;
    }
    return t;
}
int main()
{
    int num=0;
    long long temp;
    scanf("%lld",&temp);
    long long ty=temp;
    while(temp>0)
    {
        wei[num]=temp%10;
        if(wei[num]==3||wei[num]==4||wei[num]==7)
        {
            printf("no\n");
            return 0;
        }
        temp/=10;
        num++;
    }
    if(!prime(ty))
    {
        printf("no\n");
        return 0;
    }
    long long t=0;
    for(int i=0;i<num;i++)
    {
        t*=10;
        int con=convert(wei[i]);
        t+=con;
    }
    if(!prime(t))
    {
        printf("no\n");
        return 0;
    }
    else
    {
        printf("yes\n");
        return 0;
    }
}