#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1000020;
int find(ll tmp)
{
    int res=0;
    while(tmp)
    {
        if(tmp&1)
        {
            ++res;
        }
        tmp>>=1;
    }
    return res;
}
int main()
{
    ll n,p;
    scanf("%I64d%I64d",&n,&p);
    int ans=-1;
    for(int i=1;i<=maxn;++i)
    {
        n-=p;
        if(n<=0)
        {
            break;
        }
        int t=find(n);
        if(i>=t&&i<=n)
        {
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}