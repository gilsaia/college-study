//折半枚举样例题···
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int A[4020],B[4020],C[4020],D[4020];
int CD[4020*4020];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                CD[i*n+j]=C[i]+D[j];
            }
        }
        sort(CD,CD+n*n);
        long long res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cd=-(A[i]+B[j]);
                res+=upper_bound(CD,CD+n*n,cd)-lower_bound(CD,CD+n*n,cd);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}