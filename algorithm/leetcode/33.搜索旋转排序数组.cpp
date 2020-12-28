/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,mid;
        bool inleft=(target>nums[left]);
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=nums[left]){
                if(!inleft){
                    left=mid+1;
                    continue;
                }
                if(target>nums[mid]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }else{
                if(inleft){
                    right=mid-1;
                    continue;
                }
                if(target>nums[mid]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

