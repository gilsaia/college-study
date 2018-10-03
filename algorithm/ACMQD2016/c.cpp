//···鬼知道怎么看出来的规律···
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double a,b;
        scanf("%lf%lf",&a,&b);
        if(a<=b)
        {
            printf("0.000000\n");
            continue;
        }
        else
        {
            printf("%.6lf\n",log(a)-log(b)+1);
        }
    }
    return 0;
}