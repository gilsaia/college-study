#ifndef SET_H
#define SET_H
#include<iostream>
using std::ostream;
using std::cout;
template <typename Comparable>
class set
{
    public:
    set();
    set(const BinarySearchTree &rhs):root{nullptr}
    {
        root=clone(rhs.root);
    }
    set(BinarySearchTree &&rhs);
    ~set()
    {
        makeEmpty();
    }

    const Comparable& findMin() const
    {
        return root->min->element;
    }
    const Comparable& findMax() const
    {
        return root->max->element;
    }
    bool contains(const Comparable &x) const;
    bool isEmpty() const;
    void printTree(ostream &out=cout) const;

    void makeEmpty();
    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void remove(const Comparable &x);

    set& operator=(const set &rhs);
    set& operator=(set &&rhs);
    private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode *father;
        BinaryNode *min;
        BinaryNode *max;

        BinaryNode(const Comparable &theElement,BinaryNode *lt,BinaryNode *rt,BinaryNode *ft)
        :element{theElement},left{lt},right{rt},father{ft}{min=findMin(this),max=findMax(this);}
        BinaryNode(Comparable &&theElement,BinaryNode *lt,BinaryNode *rt,BinaryNode *ft)
        :element{std::move(theElement)},left{lt},right{rt},father{ft}{min=findMin(this),max=findMax(this);}
    };

    BinaryNode *root;

    void insert(const Comparable &x,BinaryNode *&t)
    {
        if(t==nullptr)
        {
            t=new BinaryNode{x,nullptr,nullptr,t};
        }
        else if(x<t->element)
        {
            insert(x,t->left);
            t->min=findMin(t);
        }
        else if(t->element<x)
        {
            insert(x,t->right);
            t->max=findMax(t);
        }
        else
        ;
    }
    void insert(Comparable &&x,BinaryNode *&t)
    {
        if(t==nullptr)
        {
            t=new  BinaryNode{std::move(x),nullptr,nullptr,t};
        }
        else if(x<t->element)
        {
            insert(x,t->left);
        }
        else if(t->element<x)
        {
            insert(x,t->right);
        }
        else
        ;
    }
    void remove(const Comparable &x,BinaryNode *&t)
    {
        if(t==nullptr)
        {
            return;
        }
        if(x<t->element)
        {
            remove(x,t->left);
        }
        else if(t->element<x)
        {
            remove(x,t->right);
        }
        else if(t->left!=nullptr&&t->right!=nullptr)
        {
            t->element=findMin(t->right)->element;
            remove(t->element,t->right);
        }
        else
        {
            t=(t->left!=nullptr)?t->left:t->right;
            delete t->father;
        }
    }
    BinaryNode *findMin(BinaryNode *t) const;
    BinaryNode *findMax(BinaryNode *t) const;
    bool contains(const Comparable &x,BinaryNode *t) const;
    void makeEmpty(BinaryNode *&t)
    {
        if(t!=nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t=nullptr;
    }
    void printTree(BinaryNode *t,ostream &out) const;
    BinaryNode *clone(BinaryNode *t) const
    {
        if(t==nullptr)
        {
            return nullptr;
        }
        else
        {
            return new BinaryNode{t->element,clone(t->left),clone(t->right),t};
        }
    }
};
template <typename Comparable>
bool set<Comparable>::contains(const Comparable &x) const
{
    return contains(x,root);
}
template <typename Comparable>
void set<Comparable>::insert(const Comparable &x)
{
    insert(x,root);
}
template <typename Comparable>
void set<Comparable>::remove(const Comparable &x)
{
    remove(x,root);
}
template <typename Comparable>
bool set<Comparable>::contains(const Comparable &x,BinaryNode *t) const
{
    if(t==nullptr)
    {
        return false;
    }
    else if(x<t->element)
    {
        return contains(x,t->left);
    }
    else if(t->element<x)
    {
        return contains(x,t->right);
    }
    else
    {
        return true;
    }
}
template <typename Comparable>
set<Comparable>::BinaryNode * set<Comparable>::findMin(BinaryNode *t) const
{
    if(t==nullptr)
    {
        return nullptr;
    }
    if(t->left==nullptr)
    {
        return t;
    }
    return findMin(t->left);
}
template <typename Comparable>
set<Comparable>::BinaryNode * set<Comparable>::findMax(BinaryNode *t) const
{
    if(t!=nullptr)
    {
        while(t->right!=nullptr)
        {
            t=t->right;
        }
    }
    return t;
}
#endif