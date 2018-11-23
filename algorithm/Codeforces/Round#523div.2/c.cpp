#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll dp[100010];
set<int> map[1000010];
int main()
{
    ll n;
    dp[0]=1;
    scanf("%I64d",&n);
    for(int i=1;i<=1000000;++i)
    {
        for(int j=i;j<=1000000;j+=i)
        {
            map[j].insert(i);
        }
    }
    for(int i=1;i<=n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        if(map[tmp].size()==1)
        {
            dp[1]++;
            continue;
        }
        for(auto it=map[tmp].lower_bound(i);it!=map[tmp].begin();--it)
        {
            dp[*it]+=dp[*it-1];
            dp[*it]%=MOD;
        }
        dp[1]++;
    }
    ll sum=0;
    for(int i=1;i<=n;++i)
    {
        sum+=dp[i];
        sum%=MOD;
    }
    printf("%I64d",sum);
    return 0;
}