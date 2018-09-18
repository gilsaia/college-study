#include<algorithm>
#include<vector>
using std::vector;
using std::swap;
template <typename Object>
class selflist
{
    public:
    void push(Object x)
    {
        data.push_back(x);
    }
    void find(Object x)
    {
        int num=-1;
        for(int i=0;i<data.size;i++)
        {
            if(data[i]==x)
            {
                num=i;
                break;
            }
        }
        if(num==-1)
        {
            return;
        }
        Object tmp=data[num];
        for(int i=0;i<=num;i++)
        {
            swap(data[i],tmp);
        }
    }
    private:
    vector<Object> data;
}