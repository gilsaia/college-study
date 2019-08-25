#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int time[100020];
int k;
bool cmp(int a,int b)
{
    return a%k<b%k;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        ll ans=0,rest=0,sum=0;
        int n;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&time[i]);
            rest+=time[i]/k;
            sum+=time[i];
        }
        if(rest>=(n-1))
        {
            ans=sum;
            ans+=k;
        }
        else
        {
            sort(time,time+n,cmp);
            for(int i=0;i<=rest;++i)
            {
                ans+=time[i]%k;
            }
            ll tmp=n;
            tmp*=k;
            ans+=tmp;
        }
        printf("%lld\n",ans);
    }
    return 0;
}