#include<vector>
#include<queue>
using std::queue;
using std::vector;
template <typename Comparable>
class BinaryHeap
{
    public:
    explicit BinaryHeap(int capacity=100);
    explicit BinaryHeap(const vector<Comparable> &itmes);

    bool isEmpty()const;
    const Comparable &findMin()const;

    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void deleteMin();
    void deleteMin(Comparable &minItem);
    void makeEmpty();
    int findlower(Comparable &x);
    private:
    int currentSize;
    vector<Comparable> array;
    void buildHeap();
    void percolateDown(int hole);
};
template <typename Comparable>
int BinaryHeap<Comparable>::findlower(Comparable &x)
{
    queue<int> thefind;
    if(array[1]<x)
    {
        thefind.push(1);
    }
    int ans=0;
    while(!thefind.empty())
    {
        int biao=thefind.front();
        thefind.pop();
        ++ans;
        if(biao*2<currentSize&&array[biao*2]<x)
        {
            thefind.push(biao*2);
        }
        if((biao*2+1)<currentSize&&array[biao*2+1]<x)
        {
            thefind.push(biao*2+1);
        }
    }
    return ans;
}
template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
    int child;
    Comparable tmp=std::move(array[hole]);
    for(;hole*2<=currentSize;hole=child)
    {
        child=hole*2;
        if(child!=currentSize&&array[child+1]<array[child])
        {
            ++child;
        }
        if(array[child]<tmp)
        {
            array[hole]=std::move(array[child]);
        }
        else
        {
            break;
        }
    }
    array[hole]=std::move(tmp);
}
template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const vector<Comparable> &items):array(items.size()+10),currentSize{items.size()}
{
    for(int i=0;i<items.size();++i)
    {
        array[i+1]=items[i];
    }
    buildHeap();
}
template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
    for(int i=currentSize/2;i>0;--i)
    {
        percolateDown(i);
    }
}