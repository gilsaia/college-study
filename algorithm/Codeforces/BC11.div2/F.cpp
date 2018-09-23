#include<cstdio>
using namespace std;
typedef long long ll;
ll save[200010],f,x;
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%I64d",&save[i]);
    }
    scanf("%I64d%I64d",&x,&f);
    ll sum=x+f,ans=0;
    for(int i=0;i<N;i++)
    {
        if(save[i]>x)
        {
            ll rest=save[i]-x;
            ans+=rest/(x+f);
            if(rest%(x+f)!=0)
            {
                ++ans;
            }
        }
    }
    ans*=f;
    printf("%I64d\n",ans);
    return 0;
}