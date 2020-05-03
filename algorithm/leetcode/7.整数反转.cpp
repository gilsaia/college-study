/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long long intmax=(1<<31)-1,intmin=(1<<31)*(-1);
        long long ant=x,res=0;
        while(ant!=0){
            res*=10;
            res+=ant%10;
            ant/=10;
        }
        if(res<intmin||res>intmax){
            return 0;
        }
        return res;
    }
};
// @lc code=end

