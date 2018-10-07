#include<cstdio>
using namespace std;
int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        long long ans=n*(n+1);
        ans/=2;
        printf("%lld\n\n",ans);
    }
    return 0;
}