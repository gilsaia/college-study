#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
long long modexp(long long a, long long b, ll mod)
{
    long long res=1;
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
ll pre[1000020];
ll inv[1000020];
int main()
{
    pre[0]=0,pre[1]=1;
    inv[1]=1;
    for(int i=2;i<1000020;++i)
    {
        pre[i]=pre[i-1]*i;
        pre[i]%=MOD;
        inv[i]=modexp(i,MOD-2,MOD);
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,x;
        scanf("%d%d",&n,&x);
        ll ans=1;
        for(int i=x+1;i<=n;++i)
        {
            ans-=inv[i];
            ans%=MOD;
        }
        ans=(ans+MOD)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}