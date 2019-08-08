#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
double dp[120][120],todiv[120],c[120][120];
int main()
{
    c[0][0]=1;
    for(int i=1;i<=100;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=100;++j)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    todiv[0]=1;
    for(int i=1;i<=100;++i)
    {
        todiv[i]=todiv[i-1]/2;
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        dp[0][0]=1;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<=n;++j)
            {
                if(dp[i][j]==0)
                {
                    continue;
                }
                for(int t=0;t<=k;++t)
                {
                    if((n-j)>=k)
                    {
                        dp[i+1][t+j]+=(c[k][t]*todiv[k]*dp[i][j]);
                    }
                    else
                    {
                        int back=n-j;
                        int needfront=k-back;
                        dp[i+1][j-needfront+t]+=(c[k][t]*todiv[k]*dp[i][j]);
                    }
                }
            }
        }
        double ans=0;
        for(int i=1;i<=n;++i)
        {
            ans+=dp[m][i]*i;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}