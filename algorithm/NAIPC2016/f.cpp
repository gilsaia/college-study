//dp问题···还好不是很难想到···
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=1e9+7;
int dp[110][10010];
int main()
{
    int n,w,h,mint;
    scanf("%d%d%d",&n,&w,&h);
    dp[0][n]=1;
    mint=n;
    for(int i=0;i<w;++i)
    {
        int nowmin=mint;
        for(int j=n;j>=nowmin;--j)
        {
            for(int t=0;t<=h;++t)
            {
                if((j-t)>=0)
                {
                    dp[i+1][j-t]+=dp[i][j];
                    dp[i+1][j-t]%=MOD;
                    mint=min(mint,j-t);
                }
                else
                {
                    break;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;++i)
    {
        ans+=dp[w][i];
        ans%=MOD;
    }
    if(n/w<h)
    {
        ans-=(n/w+1);
    }
    else
    {
        ans-=(h+1);
    }
    ans=(ans+MOD)%MOD;
    printf("%d\n",ans);
    return 0;
}