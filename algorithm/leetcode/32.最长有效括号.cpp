/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include<string>
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        stack<int> sta;
        sta.push(-1);
        for(int i=0;i<s.length();++i){
            switch (s[i])
            {
            case '(':
                sta.push(i);
                break;
            case ')':
                sta.pop();
                if(sta.empty()){
                    sta.push(i);
                }else{
                    ans=max(ans,i-sta.top());
                }
                break;
            default:
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

