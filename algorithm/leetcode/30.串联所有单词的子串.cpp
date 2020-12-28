/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty()||words.empty()){
            return {};
        }
        unordered_map<string,int> ti;
        int len=words[0].length(),n=words.size();
        vector<int> res;
        for(int i=0;i<words.size();++i){
            ti[words[i]]++;
        }
        for(int i=0;i<len;++i){
            int left=i,right=i,count=0;
            unordered_map<string,int> t2;
            while((right+len)<=s.size()){
                string w=s.substr(right,len);
                right+=len;
                if(!ti.count(w)){
                    count=0;
                    left=right;
                    t2.clear();
                }else{
                    t2[w]++;
                    count++;
                    while(t2[w]>ti[w]){
                        string tmp=s.substr(left,len);
                        count--;
                        t2[tmp]--;
                        left+=len;
                    }
                    if(count==n){
                        res.push_back(left);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

