#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct inter
{
    int start,end,effeci;
    bool operator<(const inter &rhs) const
    {
        return start<rhs.start;
    }
};
inter tims[1020];
int dp[1020];
int main()
{
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d",&tims[i].start,&tims[i].end,&tims[i].effeci);
    }
    sort(tims,tims+m);
    int ans=0;
    for(int i=0;i<m;++i)
    {
        dp[i]=max(dp[i],tims[i].effeci);
        for(int j=0;j<i;++j)
        {
            if((tims[j].end+r)<=tims[i].start)
            {
                dp[i]=max(dp[i],dp[j]+tims[i].effeci);
            }
        }
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}