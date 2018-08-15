/*开始思路是根据时间进行dp，后来意识到会tle，自行优化显然并没有优化好
看了题解发现可以利用时间段dp，根据时间开始差别判别能否判断即可，最后要注意的是
最后输出的时间不一定为dp[max]，有可能之前的最大值比考虑最后一次的大
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[1010];
struct milk
{
    int star,en,effen;
};
milk inter[1020];
bool cmp(milk a,milk b)
{
    if(a.star==b.star)
    {
        return a.en<b.en;
    }
    else
    {
        return a.star<b.star;
    }
}
int main()
{
    int N,M,R;
    scanf("%d%d%d",&N,&M,&R);
    for(int i=1;i<=M;i++)
    {
        scanf("%d%d%d",&inter[i].star,&inter[i].en,&inter[i].effen);
        inter[i].en+=R;
    }
    sort(inter,inter+M+1,cmp);
    for(int i=1;i<=M;i++)
    {
        dp[i]=inter[i].effen;
        for(int t=1;t<i;t++)
        {
            if(inter[t].en<=inter[i].star)
            {
                dp[i]=max(dp[i],dp[t]+inter[i].effen);
            }
        }
    }
    int temp=0;
    for(int i=1;i<=M;i++)
    {
        if(dp[i]>temp)
        {
            temp=dp[i];
        }
    }
    printf("%d\n",temp);
    return 0;
}