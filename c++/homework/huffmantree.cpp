#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<utility>
#include<vector>
#include<map>
using std::vector;
using std::map;
using std::make_pair;
using std::pair;
using std::string;
using std::memset;
using std::getline;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::priority_queue;
using std::fstream;
using std::ifstream;
using std::ofstream;
template <typename Save>
struct HuffmantreeNode
{
    int weight;
    Save element;
    HuffmantreeNode *left,*right;
    HuffmantreeNode(int wei=0,Save ele=0,HuffmantreeNode *l=nullptr,HuffmantreeNode *r=nullptr):
    weight{wei},element{ele},left{l},right{r}{}
    bool operator<(const HuffmantreeNode &rhs)
    {
        if(weight==rhs.weight)
        {
            return element>rhs.element;
        }
        return weight>rhs.weight;
    }
};
template <typename Save>
struct HuffmantreeComparable
{
    bool operator(HuffmantreeNode<Save> *a,HuffmantreeNode<Save> *b)
    {
        return (*a)<(*b);
    }
};
template <typename Save>
class Huffmantree
{
    public:
    void buildTree(istream &in,ostream &out)
    {
        map<Save,int> tocount;
        string theline;
        while(getline(in,theline))
        {
            for(auto i:theline)
            {
                tocount[i]++;
            }
        }
        priority_queue<HuffmantreeNode<Save>*,vector<HuffmantreeNode<Save>>,HuffmantreeComparable<Save>> que;
        for(auto i=tocount.begin();i!=tocount.end();i++)
        {
            HuffmantreeNode<Save> *tmp=new HuffmantreeNode<Save>(i->second,i->first);
            que.push(tmp);
        }
        HuffmantreeNode<Save> *thelast=nullptr;
        while(que.size()>1)
        {
            HuffmantreeNode<Save> *first=que.top();
            que.pop();
            HuffmantreeNode<Save> *second=que.top();
            que.pop();
            thelast=new HuffmantreeNode<Save>(first->weight+second->weight,(Save)0,first,second);
            que.push(thelast);
        }
        root=que.top();
    }
    private:
    HuffmantreeNode<Save> *root;
};