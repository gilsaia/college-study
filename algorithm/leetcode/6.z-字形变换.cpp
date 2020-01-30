/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        string *res=new string[numRows];
        int index=0,curlin=0,dir=0;
        while(index<s.length()){
            res[curlin]+=s[index++];
            if(dir){
                --curlin;
                if(curlin==0){
                    dir=0;
                }
            }
            else{
                ++curlin;
                if(curlin==numRows-1){
                    dir=1;
                }
            }
        }
        string ans;
        for(int i=0;i<numRows;++i){
            ans+=res[i];
        }
        return ans;
    }
};
// @lc code=end

