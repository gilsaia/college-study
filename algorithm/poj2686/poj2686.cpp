//状态压缩例题···emmmmmmmm感觉好像还可以···
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1e9;
int n,m,p,a,b;
int d[35][35],t[10];
double dp[1<<8][32];
int main()
{
    while(scanf("%d%d%d%d%d",&n,&m,&p,&a,&b))
    {
        if(!(n||m))
        {
            break;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t[i]);
        }
        for(int i=0;i<=m;i++)
        {
            fill(d[i],d[i]+m+1,-1);
        }
        for(int i=0;i<p;i++)
        {
            int x,y,dis;
            scanf("%d%d%d",&x,&y,&dis);
            d[x][y]=dis;
            d[y][x]=dis;
        }
        for(int i=0;i<1<<n;i++)
        {
            fill(dp[i],dp[i]+m+1,INF);
        }
        dp[(1<<n)-1][a]=0;
        double res=INF;
        for(int S=(1<<n)-1;S>=0;--S)
        {
            res=min(res,dp[S][b]);
            for(int v=1;v<=m;++v)
            {
                for(int i=0;i<n;i++)
                {
                    if(S>>i&1)
                    {
                        for(int u=1;u<=m;++u)
                        {
                            if(d[v][u]>=0)
                            {
                                dp[S&~(1<<i)][u]=min(dp[S&~(1<<i)][u],dp[S][v]+(double)d[v][u]/t[i]);
                            }
                        }
                    }
                }
            }
        }
        if(res==INF)
        {
            printf("Impossible\n");
            continue;
        }
        printf("%.3f\n",res);
    }
    return 0;
}