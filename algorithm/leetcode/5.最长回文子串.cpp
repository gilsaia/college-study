/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include<string>
#include<cstring>
using namespace std;
// @lc code=start

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
        {
            return string();
        }
        int dp[1020][1020],ans=0,start=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<s.length();++i){
            dp[i][i]=1;
            ans=1;
        }
        for(int i=0;i<s.length()-1;++i){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                ans=2,start=i;
            }
        }
        for(int i=2;i<s.length();++i){
            for(int j=0;j+i<s.length();++j){
                if(dp[j+1][j+i-1]&&s[j]==s[j+i]){
                    dp[j][j+i]=1;
                    ans=i+1,start=j;
                }
            }
        }
        return s.substr(start,ans);
    }
};
// @lc code=end

