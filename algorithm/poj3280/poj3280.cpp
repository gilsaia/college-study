//字符串dp问题，注意可在字符串的任意位置添加或删除
#include<iostream>
#include<string>
using namespace std;
int dp[2010][2010];
int cost[130];
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int N,M;
    cin>>N>>M;
    string s;
    cin>>s;
    for(int i=0;i<N;i++)
    {
        char k;
        int x,y;
        cin>>k>>x>>y;
        cost[k]=min(x,y);
    }
    for(int i=M-1;i>=0;i--)
    {
        for(int j=i+1;j<M;j++)
        {
            dp[i][j]=min(dp[i+1][j]+cost[s[i]],dp[i][j-1]+cost[s[j]]);
            if(s[i]==s[j])
            {
                dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            }
        }
    }
    cout<<dp[0][M-1]<<endl;
    return 0;
}