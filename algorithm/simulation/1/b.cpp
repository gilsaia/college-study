#include<cstdio>
using namespace std;
typedef long long ll;
ll MOD=192600817;
ll find[40020],sum[40020];
void swap(ll &a,ll &b)
{
    ll tmp=a;
    a=b;
    b=tmp;
}
int main()
{
    find[0]=1,find[1]=1;
    for(int i=2;i<40010;++i)
    {
        find[i]=(find[i-1]+find[i-2])%MOD;
    }
    for(int i=0;i<40010;++i)
    {
        find[i]=(find[i]*find[i])%MOD;
    }
    sum[0]=find[0];
    for(int i=1;i<40010;++i)
    {
        sum[i]=(sum[i-1]+find[i])%MOD;
    }
    int Q;
    while(scanf("%d",&Q)!=EOF)
    {
        for(int i=0;i<Q;++i)
        {
            ll a,b,c,d;
            scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
            if(a>c)
            {
                swap(a,c);
                swap(b,d);
            }
            else if(a==c&&b>d)
            {
                swap(a,c);
                swap(b,d);
            }
            ll start=a*4+b,tend=c*4+d;
            ll res=(sum[tend]-sum[start]+find[start]+MOD)%MOD;
            printf("%lld\n",res);
        }
    }
    return 0;
}