/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int tabnum[10]={0,0,3,3,3,3,3,4,3,4};
        char table[10][10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res[2];
        if(!digits.length()){
            return res[0];
        }
        res[0].push_back("");
        for(int i=0;i<digits.length();++i){
            int num=digits[i]-'0';
            res[(i+1)%2].clear();
            for(int j=0;j<res[i%2].size();++j){
                for(int t=0;t<tabnum[num];++t){
                    res[(i+1)%2].push_back(res[i%2][j]+table[num][t]);
                }
            }
        }
        return res[digits.length()%2];
    }
};
// @lc code=end

