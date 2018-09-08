#include<vector>
using namespace std;
template <typename object>
vector<object> ADTor(vector<object> &a,vector<object> &b)
{
    int ai=0,bi=0,amax=a.size(),bmax=b.size();
    vector<object> ans;
    while(!(ai>=amax&&bi>=bmax))
    {
        if(a<amax&&b<bmax)
        {
            if(a[ai]==b[bi])
            {
                ans.push_back(a[ai]);
                ai++;
                bi++;
            }
            else if(a[ai]<b[bi])
            {
                ans.push_back(a[ai]);
                ai++;
            }
            else
            {
                ans.push_back(b[bi]);
                bi++;
            }
        }
        else if(a<amax)
        {
            ans.push_back(a[ai]);
            ai++;
        }
        else
        {
            ans.push_back(b[bi]);
            bi++;
        }
    }
    return ans;
}