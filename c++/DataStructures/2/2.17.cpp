#include<vector>
using namespace std;
//a
int minsum(const vector<int> &a)
{
    int minSum=0,thisSum=0;
    for(int i=0;i<a.size();i++)
    {
        thisSum+=a[i];
        if(thisSum<minSum)
        {
            minSum=thisSum;
        }
        else if(thisSum>0)
        {
            thisSum=0;
        }
    }
    return minSum;
}