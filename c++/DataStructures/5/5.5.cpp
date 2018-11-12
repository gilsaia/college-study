#include<vector>
#include<list>
#include<algorithm>
using std::vector;
using std::list;
template <typename HashedObj>
class HashTable
{
public:
    HashTable(int size=101)
    {
        theLists.resize(size);
        currentSize=size;
    }
    bool insert(HashedObj &x)
    {
        size_t num=myhash(x)%currentSize;
        theLists[num].push_back(x);
    }
    bool contains(HashedObj &x)
    {
        size_t num=myhash(x)%currentSize;
        if(!theLists[num].empty())
        {
            auto beg=theLists[num].begin();
            while(beg!=theLists[num].end())
            {
                if(*beg==x)
                {
                    return true;
                }
                ++beg;
            }
        }
        return false;
    }
private:
    vector<list<HashedObj>> theLists;
    int currentSize;
    size_t myhash(const HashedObj &x)const;
};