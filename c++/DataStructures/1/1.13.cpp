#include<vector>
using namespace std;
template <typename T>
class Collection
{
    vector<T> Data;
public:
    bool isEmpty()
    {
        return Data.empty();
    }
    void makeEmpty()
    {
        Data.clear();
    }
    void insert(T x)
    {
        Data.push_back(x);
    }
    void remove()
    {
        Data.pop_back();
    }
    bool contains(T x)
    {
        for(int i=0;i<Data.size();i++)
        {
            if(Data[i]==x)
            {
                return true;
            }
        }
        return false;
    }
    Collection():Data(){};
};