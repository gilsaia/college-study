/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }
    int strStr(string haystack, string needle) {
        vector<int> next=prefix_function(needle);
        int j=0,i=0;
        for(i=0;i<haystack.length();++i){
            if(j==needle.length()){
                break;
            }
            while(haystack[i]!=needle[j]&&j){
                j=next[j-1];
            }
            if(haystack[i]==needle[j]){
                ++j;
            }
        }
        if(j==needle.length()){
            i-=j;
        }else{
            i=-1;
        }
        return i;
    }
};
// @lc code=end

