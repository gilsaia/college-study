/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        return res;
    }
};
// @lc code=end

