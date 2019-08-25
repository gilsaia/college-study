#include<cstdio>
#include<algorithm>
using namespace std;
int ax[1020],ay[1020];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&ax[i],&ay[i]);
        }
        double ans=0;
        double tmp=(double)(ax[1]*ay[1])/2;
        ans+=tmp;
        for(int i=1;i<n-2;++i)
        {
            tmp=(ax[i+1]-ax[i])*(ay[i+1]+ay[i]);
            tmp/=2;
            ans+=tmp;
        }
        tmp=(double)(ax[n-1]-ax[n-2])*ay[n-2]/2;
        ans+=tmp;
        printf("%.6lf\n",ans);
    }
    return 0;
}