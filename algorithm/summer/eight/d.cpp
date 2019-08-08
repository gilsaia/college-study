#include<algorithm>
#include<cstdio>
using namespace std;
typedef unsigned long long ll;
const ll MOD=1e9+7;
ll modexp(ll a, ll b, ll mod)
{
    ll res=1;
    while(b>0)
    {
        //a=a%mod;(有时候n的值太大了会超出long long的储存，所以要先取余)
        if(b&1)//&位运算：判断二进制最后一位是0还是1，&的运算规则为前后都是1的时候才是1；
            res=res*a%mod;
        b=b>>1;//相当于除以2；
        a=a*a%mod;
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        ll tmp;
        scanf("%llu",&tmp);
        --tmp;
        tmp%=(MOD-1);
        ll ans=modexp(2,tmp,MOD);
        ans%=MOD;
        printf("Case #%d: %llu\n",i,ans);
    }
    return 0;
}