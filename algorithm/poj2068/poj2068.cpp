//一样的必胜态必败态转移问题···
#include<cstdio>
#include<cstring>
using namespace std;
int dp[22][10020];
int n,s,stone[22];
int dfs(int i,int s)
{
    if(i>=n*2)
    {
        i=0;
    }
    if(dp[i][s]!=-1)
    {
        return dp[i][s];
    }
    for(int j=1;j<=stone[i];++j)
    {
        int t=s-j;
        if(t<0)
        {
            break;
        }
        if(!dfs(i+1,t))
        {
            return dp[i][s]=1;
        }
    }
    return dp[i][s]=0;
}
int main()
{
    while(~scanf("%d",&n),n)
    {
        scanf("%d",&s);
        for(int i=0;i<n*2;++i)
        {
            scanf("%d",&stone[i]);
        }
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n*2;++i)
        {
            dp[i][0]=1;
        }
        int ans=dfs(0,s);
        if(ans)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }       
    }
    return 0;
}