/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int up=-1,down=-1;
        for(int i=nums.size()-1;i>0;--i){
            if(nums[i-1]<nums[i]){
                up=i-1;
                for(int i=nums.size()-1;i>=0;--i){
                    if(nums[i]>nums[up]){
                        down=i;
                        break;
                    }
                }
                break;
            }
        }
        if(up>=0){
            swap(nums[up],nums[down]);
        }
        for(int i=up+1,j=nums.size()-1;i<j;++i,--j){
            swap(nums[i],nums[j]);
        }
        return;
    }
};
// @lc code=end

