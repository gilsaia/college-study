#include<vector>
using namespace std;
struct toreturn
{
    int sum;
    vector<int> order;
};
toreturn maxSubSum(const vector<int> & a)
{
    toreturn tor;
    vector<int> save;
    int maxSum=0,thisSum=0;
    for(int j=0;j<a.size();j++)
    {
        thisSum+=a[j];
        save.push_back(j);
        if(thisSum>maxSum)
        {
            maxSum=thisSum;
            tor.sum=maxSum;
            tor.order=save;
        }
        else if(thisSum<0)
        {
            thisSum=0;
            save.clear();
        }
    }
    return tor;
}