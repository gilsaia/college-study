/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size(),mid=0;
        while(l<r){
            mid=(l+r)/2;
            if(nums[mid]>nums[l]){
                l=mid;
            }else{
                r=mid;
            }
        }
        int rota=l+1;
        if(target<nums[0]){
            int ind=lower_bound(nums.begin()+rota,nums.end(),target)-nums.begin();
            if(ind<nums.size()&&nums[ind]==target){
                return ind;
            }
        }else{
            int ind=lower_bound(nums.begin(),nums.begin()+rota,target)-nums.begin();
            if(ind<nums.size()&&nums[ind]==target){
                return ind;
            }
        }
        return -1;
    }
};
// @lc code=end

