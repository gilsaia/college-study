#ifndef B_TREE_H
#define B_TREE_H
#include<vector>
#include<queue>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<iomanip>
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
    B_Tree_Node(size_t num=2,bool leaf=true,B_Tree_Node *parent=nullptr):father(parent),isleaf(leaf),used(0),order(num)
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
};
template <typename Save>
class B_Tree
{
    public:
    B_Tree(size_t num=2):order(num),root(nullptr)
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
};
#endif