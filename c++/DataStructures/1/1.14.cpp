#include<vector>
using namespace std;
template<typename Comparable>
class OrderedCollection
{
    vector<Comparable> dat;
public:
    bool isEmpty()
    {
        return dat.empty();
    }
    void makeEmpty()
    {
        dat.clear();
    }
    void insert(Comparable x)
    {
        dat.push_back(x);
    }
    void remove()
    {
        dat.pop_back();
    }
    Comparable& findMin()
    {
        int ans=0;
        for(int i=0;i<dat.size();i++)
        {
            if(dat[i]<dat[ans])
            {
                ans=i;
            }
        }
        return dat[ans];
    }
    Comparable& findMax()
    {
        int ans=0;
        for(int i=0;i<dat.size();i++)
        {
            if(dat[i]>dat[ans])
            {
                ans=i;
            }
        }
        return dat[ans];
    }
};