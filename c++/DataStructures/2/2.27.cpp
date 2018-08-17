#include<vector>
using namespace std;
bool findmatrixmax(vector<vector<int>> a,int k)
{
    int i = a.size()-1, j = 0;
    while(i>=0 && j<=a.size()-1)
    {
        if(a[i][j] > k)
        {
            i--;
        }   
        else if(a[i][j] < k)
        {
            j++;
        }
        else   
        {
        return true;
        }
    }
    return false;
}