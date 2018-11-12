#ifndef B_TREE_H
#define B_TREE_H
#include<vector>
#include<queue>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<iomanip>
using std::ostream;
using std::cout;
using std::endl;
using std::setw;
using std::vector;
using std::move;
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
        Elements.resize(order);
        children.resize(order+1);
        for(int i=0;i<children.size();++i)
        {
            children[i]=nullptr;
        }
    }
    void splitChild(int i,B_Tree_Node *y)
    {
        B_Tree_Node *change=new B_Tree_Node(y->order,y->isleaf);
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
            Elements[i+1]=k;
            ++used;
        }
        else
        {
            while(i>=0&&Elements[i]>element)
            {
                --i;
            }
            if(children[i+1]->used==order)
            {
                splitChild(i+1,children[i+1]);
                if(Elements[i+1]<element)
                {
                    ++i;
                }
            }
            children[i+1]->insertNonFull(k);
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
        if(idx<n&&Elements[idx]==k)
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
            if(children[idx]->used<order/2+1)
            {
                fill(idx);
            }
            if(flag&&idx>n)
            {
                children[idx-1]->remove(k);
            }
            else
            {
                children[idx]->remove(k);
            }
        }
        return;
    }
    void removeFromLeaf(size_t idx)
    {
        for(size_t i=idx+1;i<n;++i)
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
        for(int i=idx+1;i<n;++i)
        {
            Elements[i-1]=Elements[i];
        }
        for(int i=idx+2;i<=n;++i)
        {
            children[i-1]=children[i];
        }
        child->used+=sibling->used+1;
        --used;
        delete sibling;
        return;
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
            root=new B_Tree_Node<Save>(order,true);
            root->Elements[0]=element;
            root->used++;
        }
        else
        {
            if(root->used==order)
            {
                B_Tree_Node<Save> *grow=new B_Tree_Node(order,false);
                grow->children[0]=root;
                grow->splitChild(0,root);
                int i=0;
                if(grow->Elements[0]<element)
                {
                    ++i;
                }
                grow->children[i]->insertNonFull(element);
                root=grow;
            }
            else
            {
                root->insertNonFull(element);
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
            B_Tree_Node *tmp=root;
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
        return;
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
#endif