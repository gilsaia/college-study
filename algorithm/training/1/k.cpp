#include<cstdio>
typedef long long ll;
ll alg(ll n)
{
    ll tmp1=n*(n+1)/2;
    ll tmp2=n*(n+1)*(2*n+1)/6;
    return tmp1+tmp2;
}
int main()
{
    int K;
    scanf("%d",&K);
    for(int i=0;i<K;++i)
    {
        ll N,M;
        scanf("%lld%lld",&N,&M);
        ll ans=alg(M)-alg(N)+N*(N+1);
        printf("%lld\n",ans);
    }
    return 0;
}