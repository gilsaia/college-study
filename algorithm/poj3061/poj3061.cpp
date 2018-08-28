//尺取法例题·····基本照着思路看的···
#include<stdio.h>
#include<functional>
#include<algorithm>
using namespace std;
int N,S,a[100100];
void solve()
{
    int res=N+1;
    int s=0,t=0,sum=0;
    while(1)
    {
        while(t<N&&sum<S)
        {
            sum+=a[t++];
        }
        if(sum<S)
        {
            break;
        }
        res=min(res,t-s);
        sum-=a[s++];
    }
    if(res>N)
    {
        res=0;
    }
    printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&S);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        solve();
    }
    return 0;
}