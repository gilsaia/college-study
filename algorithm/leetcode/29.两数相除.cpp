/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool umin=(dividend>>31)^(divisor>>31);
        if(!dividend>>31){
            dividend=-dividend;
        }
        if(!divisor>>31){
            divisor=-divisor;
        }
        int res=0;
        while(dividend<divisor){
            int tempres=-1,tempdivisor=divisor;
            while(dividend<=(tempdivisor<<1)){
                if(tempdivisor<=(0x7fffffff)){
                    break;
                }
                tempres<<=1;
                tempdivisor<<=1;
            }
            res+=tempres;
            dividend-=tempdivisor;
        }
        if(!umin){
            if
        }
    }
};
// @lc code=end

