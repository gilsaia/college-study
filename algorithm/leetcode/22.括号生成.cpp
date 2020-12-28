/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void dfs(string pec,int &n,int now,int floor,vector<string> &res){
        if(now<n){
            pec+='(';
            ++floor;
            dfs(pec,n,now+1,floor,res);
            while(floor){
                pec+=')';
                --floor;
                dfs(pec,n,now+1,floor,res);
            }
        }else if(!floor){
            res.push_back(pec);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("",n,0,0,res);
        return res;
    }
};
// @lc code=end

