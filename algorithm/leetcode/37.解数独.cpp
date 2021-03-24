/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include<vector>
#include<cstring>
using namespace std;
// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int check[3][9][9];
        memset(check,0,sizeof(check));
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.'){
                    continue;
                }
                int num=board[i][j]-'1';
                check[0][i][num]=1;
                check[1][j][num]=1;
                check[2][i/3*3+j/3][num]=1;
            }
        }
        bool complete=false;
        while(!complete){
            complete=true;
            for(int i=0;i<9;++i){
                for(int j=0;j<9;++j){
                    if(board[i][j]!='.'){
                        continue;
                    }
                    complete=false;
                    int checkt[9]={0};
                    int remain=9;
                    for(int t=0;t<9;++t){
                        if(check[0][i][t]||check[1][j][t]||check[2][i/3*3+j/3][t]){
                            checkt[t]=1;
                            --remain;
                        }
                    }
                    if(remain==1){
                        for(int t=0;t<9;++t){
                            if(!checkt[t]){
                                board[i][j]=t+'1';
                                check[0][i][t]=1;
                                check[1][j][t]=1;
                                check[2][i/3*3+j/3][t]=1;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
};
// @lc code=end

