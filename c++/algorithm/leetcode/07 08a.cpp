#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n=A.size(),B=A[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int t=0;t<B;t++)
            {
                temp.push_back(A[i][t]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};