#include<vector>
using namespace std;
template <typename object>
vector<object> ADTand(vector<object> &a,vector<object> &b)
{
    int ai=0,bi=0,amax=a.size(),bmax=b.size();
    vector<object> ans;
    while(a<amax&&b<bmax)
    {
        if(a[ai]==b[bi])
        {
            ans.push_back(a[ai]);
            ai++;
            bi++;
        }
        else if(a[ai]<b[bi])
        {
            ai++;
        }
        else
        {
            bi++;
        }
    }
    return ans;
}