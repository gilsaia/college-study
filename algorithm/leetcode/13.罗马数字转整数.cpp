/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        char roman[14]={'I','X','C','V','L','D','M'};
        int romannum[14]={1,10,100,5,50,500,1000};
        char lim[14][2]={{'V','X'},{'L','C'},{'D','M'}};
        int limnum[14][2]={{4,9},{40,90},{400,900}};
        for(int i=0;i<s.length();++i){
            for(int j=0;j<7;++j){
                if(s[i]==roman[j]){
                    if(j<3&&(i+1)<s.length()){
                        if(s[i+1]==lim[j][0]){
                            res+=limnum[j][0];
                            ++i;
                        }else if(s[i+1]==lim[j][1]){
                            res+=limnum[j][1];
                            ++i;
                        }else{
                            res+=romannum[j];
                        }
                    }else{
                        res+=romannum[j];
                    }
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

