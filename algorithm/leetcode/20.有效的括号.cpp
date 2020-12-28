/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include<string>
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<int> sta;
        sta.push(-1);
        for(int i=0;i<s.length();++i){
            if(s[i]=='('){
                sta.push(0);
            }else if(s[i]=='['){
                sta.push(1);
            }else if(s[i]=='{'){
                sta.push(2);
            }else if(s[i]==')'){
                if(sta.top()!=0){
                    return false;
                }
                sta.pop();
            }else if(s[i]==']'){
                if(sta.top()!=1){
                    return false;
                }
                sta.pop();
            }else if(s[i]=='}'){
                if(sta.top()!=2){
                    return false;
                }
                sta.pop();
            }
        }
        if(sta.size()>1){
            return false;
        }
        return true;
    }
};
// @lc code=end

