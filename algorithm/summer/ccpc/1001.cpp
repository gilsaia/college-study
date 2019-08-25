#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        ll A,B;
        scanf("%lld%lld",&A,&B);
        ll c=A&B;
        if(c==0)
        {
            c=1;
        }
        printf("%lld\n",c);
    }
    return 0;
}