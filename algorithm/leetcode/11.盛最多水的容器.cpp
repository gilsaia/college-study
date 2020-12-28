/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int res=min(height[right],height[left])*(right-left);
        while(left<right){
            if(height[left]<=height[right]){
                int tmp=left;
                while(height[tmp]<=height[left]&&tmp<right){
                    ++tmp;
                }
                res=max(res,min(height[tmp],height[right])*(right-tmp));
                left=tmp;
            }else{
                int tmp=right;
                while(height[tmp]<=height[right]&&tmp>left){
                    --tmp;
                }
                res=max(res,min(height[tmp],height[left])*(tmp-left));
                right=tmp;
            }
        }
        return res;
    }
};
// @lc code=end

