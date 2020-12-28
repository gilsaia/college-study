/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }else if(x==0){
            return true;
        }
        char tmp[37];
        int length=0;
        while(x){
            tmp[length]=(x%10)-'0';
            x/=10;
            length++;
        }
        for(int i=0;i<length/2+1;++i){
            if(tmp[i]!=tmp[length-i-1]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

