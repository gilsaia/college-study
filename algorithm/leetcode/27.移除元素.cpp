/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        for(;i<nums.size();++i){
            if(nums[i]==val){
                continue;
            }
            nums[j]=nums[i];
            ++j;
        }
        return j;
    }
};
// @lc code=end

