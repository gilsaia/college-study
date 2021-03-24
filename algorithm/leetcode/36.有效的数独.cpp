/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include<vector>
#include<cstring>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int check[3][9][9];
        memset(check,0,sizeof(check));
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.'){
                    continue;
                }
                int num=board[i][j]-'1';
                if(check[0][i][num]||check[1][j][num]||check[2][i/3*3+j/3][num]){
                    return false;
                }
                check[0][i][num]=1;
                check[1][j][num]=1;
                check[2][i/3*3+j/3][num]=1;
            }
        }
        return true;
    }
};
// @lc code=end

