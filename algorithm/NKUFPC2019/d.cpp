#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int t,n;
    scanf("%d%d",&t,&n);
    int a[4];
    for(int i=0;i<t;++i)
    {
        scanf("%d",&a[i]);
    }
    switch (t)
    {
        case 0:
            printf("0\n");
            break;
        case 1:
            {
                ll ans1=n-1;
                ans1/=a[0];
                ++ans1;
                printf("%lld\n",ans1);
                break;
            }
        case 2:
            {
                ll p2=(n-1)/a[0];
                ll ans2=p2+1+(a[0]/a[1])*p2*(p2+1)/2;
                printf("%lld\n",ans2);
                break;
            }
        case 3:
            {
                ll p3=(n-1)/a[0];
                ll q3=a[0]/a[1];
                ll m3=a[1]/a[2];
                ll ans3=p3+1+q3*p3*(p3+1)/2+m3*(q3*p3*(p3+1)/2+q3*q3*p3*(p3+1)*(2*p3+1)/6)/2;
                printf("%lld\n",ans3);
                break;
            }
        case 4:
            {
                ll q4=a[1]/a[2];
                ll m4=a[2]/a[3];
                ll ans4=0;
                for(int i=1;i<=n;i+=a[0])
                {
                    ll p4=(i-1)/a[1];
                    ans4=ans4+p4+1+q4*p4*(p4+1)/2+m4*(q4*p4*(p4+1)/2+q4*q4*p4*(p4+1)*(2*p4+1)/6)/2;
                }
                printf("%lld\n",ans4);
                break;
            }
        default:
            break;
    }
    return 0;
}