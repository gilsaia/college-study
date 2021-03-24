/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(l>=nums.size()||nums[l]!=target){
            vector<int> res{-1,-1};
            return res;
        }
        int r=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        vector<int> res{l,r-1};
        return res;
    }
};
// @lc code=end

