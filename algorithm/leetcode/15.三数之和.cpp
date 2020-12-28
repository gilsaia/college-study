/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();){
            if(nums[i]>0){
                break;
            }
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int an=nums[i]+nums[left]+nums[right];
                if(an==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    int pos=left;
                    while(pos<right&&nums[pos]==nums[left]){
                        ++pos;
                    }
                    left=pos;
                }else if(an<0){
                    int pos=left;
                    while(pos<right&&nums[pos]==nums[left]){
                        ++pos;
                    }
                    left=pos;
                }else if(an>0){
                    int pos=right;
                    while(pos>left&&nums[pos]==nums[right]){
                        --pos;
                    }
                    right=pos;
                }
            }
            int pos=i;
            while(pos<nums.size()&&nums[pos]==nums[i]){
                ++pos;
            }
            i=pos;
        }
        return res;
    }
};
// @lc code=end

