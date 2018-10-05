#include<set>
#include<utility>
using std::pair;
using std::set;
using std::make_pair;
template <typename KeyType,typename ValueType>
class map
{
    public:
    map(){}
    void insert(pair<KeyType,ValueType> &i)
    {
        save.insert(i);
    }
    int size()
    {
        return save.size();
    }
    bool empty()
    {
        return save.empty();
    }
    void clear()
    {
        save.clear();
    }
    ValueType & operator[](KeyType a)
    {
        auto tofind=save.lower_bound(make_pair(a,ValueType{}));
        return *tofind.second;
    }
    private:
    set<pair<KeyType,ValueType>> save;
};