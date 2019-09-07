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