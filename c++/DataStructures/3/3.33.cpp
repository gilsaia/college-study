#ifndef CIRCULAR_ARRAY_H
#define CIRCULAR_ARRAY_H
#include<vector>
using std::vector;
template <typename Object>
class Queue
{
    const int SIZE=10000;
    int size;
    vector<Object>::iterator head,tail;
    vector<Object> data;
    public:
    Queue():size(0)
    {
        data.resize(SIZE);
        tail=data.begin();
        head=tail+1;
    }
    Queue(Object &x):size(1)
    {
        data.push_back(x);
        data.resize(SIZE);
        tail=data.begin();
        head=tail+1;
    }
    void push_back(Object &x)
    {
        ++size;
        data[head]=x;
        ++head;
        if(head==data.end())
        {
            head=data.begin();
        }
        if(head+1==tail)
        {
            throw "FUCK!!!";
        }
    }
    void top()
    {
        return *tail;
    }
    void pop()
    {
        if(size)
        {
            ++tail;
            if(tail==data.end())
            {
                tail=data.begin();
            }
        }
        --size;
    }
};
int main()
{
    vector<int> t;
    vector<int>::iterator head;
}
#endif