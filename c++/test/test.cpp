#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
char input[100020];
typedef long long ll;
const ll MOD=1e9+7;
ll dp[2][2];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",input);
        stack<int> st;
        int start=0;
        for(int i=0;input[i]!='\0';++i)
        {
            if(start)
            {
                st.push(input[i]-'0');
            }
            else
            {
                if(input[i]-'0'==1)
                {
                    start=1;
                    st.push(1);
                }
            }
        }
        dp[0][0]=1;
        dp[0][1]=dp[1][0]=dp[1][1]=0;
        ll ans=1;
        int index=1;
        while(!st.empty())
        {
            int tmp=st.top();
            st.pop();
            dp[index%2][0]=(dp[(index+1)%2][0]+dp[(index+1)%2][1])*2;
            dp[index%2][0]%=MOD;
            if(tmp)
            {
                dp[index%2][1]=dp[(index+1)%2][0]+dp[(index+1)%2][1];
                dp[index%2][1]%=MOD;
            }
            else
            {
                dp[index%2][1]=0;
            }
            ans+=dp[index%2][1];
            ++index;
            ans%=MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}