#include<vector>
using namespace std;
class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: True if and only if the matrix is Toeplitz
     */
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool ans=1;
        for(int i=m-1;i>=0;i--)
        {
            if(n!=0)
            {
                int t=0,p=i,temp=matrix[p][t];
                while(p<m&&t<n)
                {
                    if(temp==matrix[p][t])
                    {
                        p++;
                        t++;
                        continue;
                    }
                    else
                    {
                        ans=0;
                        return ans;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(n!=0)
            {
                int p=0,t=i,temp=matrix[p][t];
                while(t<n&&p<m)
                {
                    if(temp==matrix[p][t])
                    {
                        p++;
                        t++;
                        continue;
                    }
                    else
                    {
                        ans=0;
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};