/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        int romanlim[14]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        char alp[14][3]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        int pos=0;
        while(num){
            int siz=num/romanlim[pos];
            for(int i=0;i<siz;++i){
                res+=alp[pos];
            }
            num-=(siz*romanlim[pos]);
            ++pos;
        }
        return res;
    }
};
// @lc code=end

