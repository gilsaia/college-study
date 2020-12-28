/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(!strs.size()){
            return res;
        }
        res=strs[0];
        for(int i=1;i<strs.size();++i){
            res=res.substr(0,strs[i].length());
            for(int j=0;j<strs[i].length();++j){
                if(j>=res.length()||res[j]!=strs[i][j]){
                    res=res.substr(0,j);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

