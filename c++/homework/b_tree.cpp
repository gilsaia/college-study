#ifndef B_TREE_H
#define B_TREE_H
#include<vector>
#include<queue>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<sstream>
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::istringstream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::vector;
using std::move;
using std::string;
using std::getline;
using std::setw;
template <typename Save>
struct B_Tree_Node
{
    B_Tree_Node *father;
    vector<Save> Elements;
    vector<B_Tree_Node *> children;
    size_t used,order;
    bool isleaf;
    ostream &out;
    B_Tree_Node(size_t num=2,bool leaf=true,B_Tree_Node *parent=nullptr,ostream &ou=cout):father(parent),isleaf(leaf),used(0),order(num),out(ou)
    {
        Elements.resize(order+1);
        children.resize(order+2);
        for(int i=0;i<children.size();++i)
        {
            children[i]=nullptr;
        }
    }
    void splitChild(int i,B_Tree_Node *y)
    {
        B_Tree_Node *change=new B_Tree_Node(y->order,y->isleaf,nullptr,out);
        change->used=order/2;
        for(int j=0;j<order/2;++j)
        {
            change->Elements[j]=y->Elements[j+order/2+1];
        }
        if(y->isleaf==false)
        {
            for(int j=0;j<order/2+1;++j)
            {
                change->children[j]=y->children[j+order/2+1];
            }
        }
        y->used=order/2;
        for(int j=used;j>=i+1;--j)
        {
            children[j+1]=children[j];
        }
        children[i+1]=change;
        for(int j=used-1;j>=i;--j)
        {
            Elements[j+1]=Elements[j];
        }
        Elements[i]=y->Elements[order/2];
        used++;
    }
    bool insert(Save &x)
    {
        size_t cmp=used++;
        children[cmp+2]=children[cmp+1];
        while(cmp>0&&Elements[--cmp]>x)
        {
            Elements[cmp+1]=move(Elements[cmp]);
            children[cmp+1]=children[cmp];
        }
        if(cmp==0)
        {
            Elements[cmp]=x;
        }
        else
        {
            Elements[cmp+1]=x;
        }
        if(used==order)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insertNonFull(Save element)
    {
        size_t i=used-1;
        if(isleaf==true)
        {
            while(i>=0&&Elements[i]>element)
            {
                Elements[i+1]=Elements[i];
                --i;
            }
            Elements[i+1]=element;
            ++used;
        }
        else
        {
            while(i>=0&&Elements[i]>element)
            {
                --i;
            }
            children[i+1]->insertNonFull(element);
            if(children[i+1]->used>order)
            {
                splitChild(i+1,children[i+1]);
                if(Elements[i+1]<element)
                {
                    ++i;
                }
            }
        }
    }
    size_t findKey(Save k)
    {
        int idx=0;
        while(idx<used&&Elements[idx]<k)
        {
            ++idx;
        }
        return idx;
    }
    void remove(Save k)
    {
        size_t idx=findKey(k);
        if(idx<used&&Elements[idx]==k)
        {
            if(isleaf)
            {
                removeFromLeaf(idx);
            }
            else
            {
                removeFromNonLeaf(idx);
            }
        }
        else
        {
            if(isleaf)
            {
                out<<"The Element "<<k<<" is does not exist in the tree\n";
                return;
            }
            bool flag=((idx==used)?true:false);
            if(order==2)
            {
                if(children[idx]->used<=1)
                {
                    fill(idx);
                }
            }
            else if(children[idx]->used<order/2+1)
            {
                fill(idx);
            }
            if(flag&&idx>used)
            {
                children[idx-1]->remove(k);
                if(children[idx-1]->used>order)
                {
                    splitChild(idx-1,children[idx-1]);
                }
            }
            else
            {
                children[idx]->remove(k);
                if(children[idx]->used>order)
                {
                    splitChild(idx,children[idx]);
                }
            }
        }
        return;
    }
    void removeFromLeaf(size_t idx)
    {
        for(size_t i=idx+1;i<used;++i)
        {
            Elements[i-1]=Elements[i];
        }
        --used;
        return;
    }
    void removeFromNonLeaf(size_t idx)
    {
        Save k=Elements[idx];
        if(children[idx]->used>=order/2+1)
        {
            Save pred=getpred(idx);
            Elements[idx]=pred;
            children[idx]->remove(pred);
        }
        else if(children[idx+1]->used>=(order/2+1))
        {
            Save succ=getsucc(idx);
            Elements[idx]=succ;
            children[idx+1]->remove(succ);
        }
        else
        {
            merge(idx);
            children[idx]->remove(k);
        }
        return;
    }
    Save getpred(size_t idx)
    {
        B_Tree_Node *cur=children[idx];
        while(!cur->isleaf)
        {
            cur=cur->children[cur->used];
        }
        return cur->Elements[cur->used-1];
    }
    Save getsucc(size_t idx)
    {
        B_Tree_Node *cur=children[idx+1];
        while(!cur->isleaf)
        {
            cur=cur->children[0];
        }
        return cur->Elements[0];
    }
    void fill(size_t idx)
    {
        if(idx!=0&&children[idx-1]->used>=(order/2+1))
        {
            borrowFromPrev(idx);
        }
        else if(idx!=used&&children[idx+1]->used>=(order/2+1))
        {
            borrowFromNext(idx);
        }
        else
        {
            if(idx!=used)
            {
                merge(idx);
            }
            else
            {
                merge(idx-1);
            }
        }
        return;
    }
    void borrowFromPrev(size_t idx)
    {
        B_Tree_Node *child=children[idx];
        B_Tree_Node *sibling=children[idx-1];
        for(int i=child->used-1;i>=0;--i)
        {
            child->Elements[i+1]=child->Elements[i];
        }
        if(!child->isleaf)
        {
            for(int i=child->used;i>=0;--i)
            {
                child->children[i+1]=child->children[i];
            }
        }
        child->Elements[0]=Elements[idx-1];
        if(!isleaf)
        {
            child->children[0]=sibling->children[sibling->used];
        }
        Elements[idx-1]=sibling->Elements[sibling->used-1];
        child->used++;
        sibling->used--;
        return;
    }
    void borrowFromNext(size_t idx)
    {
        B_Tree_Node *child=children[idx];
        B_Tree_Node *sibling=children[idx+1];
        child->Elements[child->used]=Elements[idx];
        if(!(child->isleaf))
        {
            child->children[child->used+1]=sibling->children[0];
        }
        Elements[idx]=sibling->Elements[0];
        for(int i=1;i<sibling->used;++i)
        {
            sibling->Elements[i-1]=sibling->Elements[i];
        }
        if(!sibling->isleaf)
        {
            for(int i=1;i<=sibling->used;++i)
            {
                sibling->children[i-1]=sibling->children[i];
            }
        }
        child->used++;
        sibling->used--;
        return;
    }
    void merge(size_t idx)
    {
        B_Tree_Node *child=children[idx];
        B_Tree_Node *sibling=children[idx+1];
        child->Elements[order/2]=Elements[idx];
        for(int i=0;i<sibling->used;++i)
        {
            child->Elements[i+order/2+1]=sibling->Elements[i];
        }
        if(!child->isleaf)
        {
            for(int i=0;i<=sibling->used;++i)
            {
                child->children[i+order/2+1]=sibling->children[i];
            }
        }
        for(int i=idx+1;i<used;++i)
        {
            Elements[i-1]=Elements[i];
        }
        for(int i=idx+2;i<=used;++i)
        {
            children[i-1]=children[i];
        }
        child->used+=sibling->used+1;
        --used;
        delete sibling;
        return;
    }
    bool search(Save k)
    {
        size_t num=0;
        while(num<used&&Elements[num]<k)
        {
            ++num;
        }
        if(Elements[num]==k)
        {
            return true;
        }
        else
        {
            if(isleaf)
            {
                return false;
            }
            else
            {
                return children[num]->search(k);
            }
        }
    }
    void print()
    {
        out<<"<";
        for(int i=1;i<=used;++i)
        {
            out<<Elements[i-1]<<(i==used?'>':',');
        }
        out<<"(";
        for(int i=0;i<=used;++i)
        {
            if(children[i]!=nullptr)
            {
                children[i]->print();
                if(i!=used)
                {
                    out<<',';
                }
            }
        }
        out<<")";
    }
    void print(int space)
    {
        for(int i=0;i<used;++i)
        {
            if(children[i]!=nullptr)
            {
                children[i]->print(space+5);
            }
            out<<setw(space)<<Elements[i]<<endl;
        }
        if(children[used]!=nullptr)
        {
            children[used]->print(space+5);
        }
    }
};
template <typename Save>
class B_Tree
{
    public:
    B_Tree(size_t num=2,ostream &ou=cout):order(num),root(nullptr),out(ou)
    {
    }
    void insert(Save element)
    {
        if(root==nullptr)
        {
            root=new B_Tree_Node<Save>(order,true,nullptr,out);
            root->Elements[0]=element;
            root->used++;
        }
        else
        {
            root->insertNonFull(element);
            if(root->used>order)
            {
                B_Tree_Node<Save> *grow=new B_Tree_Node<Save>(order,false,nullptr,out);
                grow->children[0]=root;
                int i=0;
                /*if(grow->Elements[0]<element)
                {
                    ++i;
                }*/
                //grow->children[i]->insertNonFull(element);
                grow->splitChild(0,root);                
                root=grow;
            }
            else
            {
                //root->insertNonFull(element);
            }
        }
        /*B_Tree_Node<Save> *toinsert=root;
        while(toinsert->children[0]!=nullptr)
        {
            size_t cmp=0;
            while(cmp<toinsert->used&&toinsert->Elements[cmp]<element)
            {
                ++cmp;
            }
            toinsert=toinsert->children[cmp];
        }
        if(toinsert->insert(element))
        {
            divide(toinsert);
        }*/
    }
    void remove(Save k)
    {
        if(!root)
        {
            out<<"The Tree is empty"<<endl;
            return;
        }
        root->remove(k);
        if(root->used==0)
        {
            B_Tree_Node<Save> *tmp=root;
            if(root->isleaf)
            {
                root=nullptr;
            }
            else
            {
                root=root->children[0];
            }
            delete tmp;
        }
        if(root!=nullptr&&root->used>order)
            {
                B_Tree_Node<Save> *grow=new B_Tree_Node<Save>(order,false,nullptr,out);
                grow->children[0]=root;
                int i=0;
                /*if(grow->Elements[0]<element)
                {
                    ++i;
                }*/
                //grow->children[i]->insertNonFull(element);
                grow->splitChild(0,root);                
                root=grow;
            }
        return;
    }
    bool sraech(Save k)
    {
        return root->search(k);
    }
    void print()
    {
        out<<"Condition start:"<<endl;
        if(root!=nullptr)
        {
            root->print(1);
        }
        out<<"Condition end"<<endl;
    }
    private:
    bool divide(B_Tree_Node<Save> *div)
    {
        B_Tree_Node<Save> *fa=div->father;
        Save middle=div->Elements[order/2];
        if(fa->insert(div->Elements[order/2]))
        {

        }
        else
        {
            size_t cmp=0;
            while(fa->Elements[cmp]!=middle)
            {
                ++cmp;
            }

        }
    }
    B_Tree_Node<Save> *root;
    size_t order;
    ostream &out;
};
int main()
{
    int n,order;
    ifstream in("G:\\cs\\coding\\c++\\homework\\b_treeinput.txt");
    ofstream out("G:\\cs\\coding\\c++\\homework\\b_treeoutput.txt");
    in>>n>>order;
    B_Tree<int> tree(order,out);
    int num=0;
    string line;
    while(num<n)
    {
        getline(in,line);
        istringstream input(line);
        int tmp;
        while(num<n&&input>>tmp)
        {
            if(num<n-1)
            {
                char sign;
                input>>sign;
            }
            num++;
            tree.insert(tmp);
        }
    }
    tree.print();
    while(getline(in,line))
    {
        istringstream input(line);
        string opera;
        input>>opera;
        if(opera[0]=='I')
        {
            int tmp;
            input>>tmp;
            if(tree.sraech(tmp))
            {
                out<<"It has been inserted"<<endl;
            }
            else
            {
                tree.insert(tmp);
                tree.print();
            }
        }
        else if(opera[0]=='D')
        {
            int tmp;
            input>>tmp;
            if(tree.sraech(tmp))
            {
                tree.remove(tmp);
                tree.print();
            }
            else
            {
                out<<"There is no exist the element"<<endl;
            }
        }
        else
        {
            if(opera[1]=='I')
            {
                int tmp;
                while(input>>tmp)
                {
                    if(tree.sraech(tmp))
                    {
                        out<<"It has been inserted"<<endl;
                    }
                    else
                    {
                        tree.insert(tmp);
                        tree.print();
                    }
                    char sign;
                    input>>sign;
                    if(sign=='#')
                    {
                        break;
                    }
                }
            }
            else
            {
                int tmp;
                while(input>>tmp)
                {
                    if(tree.sraech(tmp))
                    {
                        tree.remove(tmp);
                        tree.print();
                    }
                    else
                    {
                        out<<"There is no exist the element"<<endl;
                    }
                    char sign;
                    input>>sign;
                    if(sign=='#')
                    {
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
#endif