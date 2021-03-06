//基本没想到思路在题解的帮助下终于明白这道题的含义了··贴一下题解方便记忆··
/*1. 当 n 为奇数时, f[n] = f[n-1], 因为只需在所有的序列前添加一个 1 即可, 所有的序列同时延迟 1 位, 不会出现重复

　　若是这个 1 和其他的1组成 2 而不是放在首位, 怎么办? 不会这样, 因为这个序列肯定已经存在了

　　证明, 假设sum(s1) = 2*k, s1内部某个1加1得到 s2, 则 sum(s2) = 2*k+1, s2 的首位仍然肯定是1, 那么 s2 也可以通过 s3 延长而来, 所以必然已经存在了

　　

2. 当 n 为偶数时, 分为两种情况

　　<1> 某个序列首位为1, 则该序列由 f(n-1) 延长而来

　　<2> 当某个序列首位为2, 则该序列没有1, 将该序列的所有元素除以 2, 则 是 f(n/2)的序列
     f[n] = f[n-1]+f[n/2] */
#include<iostream>
using namespace std;
int dp[1000010];
const int mod=1e9;
int main()
{
    dp[0]=0;dp[1]=1;
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            dp[i]=dp[i-1]+dp[i>>1];
        }
        else
        {
            dp[i]=dp[i-1];
        }
        if(dp[i]>mod)
        {
            dp[i]%=mod;
        }
    }
    cout<<dp[n];
    return 0;
}
