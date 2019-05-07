#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=0xffffffffffffff;
ll T[5020],F[5020],sum[5020];
struct team
{
    ll cost,res,time;
}dp[5020][5020];
int main()
{
    int n;
    scanf("%d",&n);
    int S;
    scanf("%d",&S);
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",&T[i],&F[i]);
    }
    sum[0]=T[0];
    for(int i=1;i<n;++i)
    {
        sum[i]=sum[i-1]+T[i];
    }
    dp[0][0].res=(T[0]+S)*F[0];
    dp[0][0].cost=F[0];
    dp[0][0].time=0;
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(j!=i)
            {
                dp[i][j].cost=dp[i-1][j].cost+F[i];
                dp[i][j].res=dp[i-1][j].res+dp[i][j].cost*T[i]+F[i]*(sum[i-1]-sum[j]+T[j]);
                dp[i][j].time=dp[i-1][j].time;
            }
            else
            {
                ll res=MAXN;
                for(int t=0;t<i;++t)
                {
                    if((dp[i-1][t].res+dp[i-1][t].cost*dp[i-1][t].time)<res)
                    {
                        res=dp[i-1][t].res+dp[i-1][t].cost*dp[i-1][t].time;
                        dp[i][j].time=dp[i-1][t].time+sum[i-1]-sum[t]+T[t]+S;
                    }
                }
                dp[i][j].res=res+(S+T[i])*F[i];
                dp[i][j].cost=F[i];
            }
        }
    }
    ll ans=MAXN;
    for(int i=0;i<n;++i)
    {
        dp[n-1][i].res+=dp[n-1][i].time*dp[n-1][i].cost;
        ans=min(ans,dp[n-1][i].res);
    }
    printf("%lld\n",dp[n-1][n-1].res);
    return 0;
}