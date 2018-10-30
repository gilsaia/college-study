#include<algorithm>
using std::max;
template <typename Comparable>
struct AvlNode
{
    Comparable element;
    AvlNode *left;
    AvlNode *right;
    int height;
    AvlNode(const Comparable &ele,AvlNode *lt,AvlNode *rt,int h=0)
    :element{ele},left{lt},right{rt},height{h}{}
    AvlNode(Comparable &&ele,AvlNode *lt,AvlNode *rt,int h=0)
    :element{std::move(ele)},left{lt},right{rt},height{h}{}
};
template <typename Comparable>
int height(AvlNode<Comparable> *t)
{
    return t==nullptr?-1:t->height;
}
template <typename Comparable>
void insert(const Comparable &x,AvlNode<Comparable> *&t)
{
    if(t==nullptr)
    {
        t=new AvlNode<Comparable>(x,nullptr,nullptr);
    }
    else if(x<t->element)
    {
        insert(x,t->left);
    }
    else if(t->element<x)
    {
        insert(x,t->right);
    }
    balance(t);
}
template <typename Comparable>
void insert(const Comparable &x,AvlNode<Comparable> *&t,int a)
{
    AvlNode<Comparable> *tmp=t;
    while(tmp!=nullptr&&x!=tmp->element)
    {
        if(x<tmp->element)
        {
            if(tmp->left==nullptr)
            {
                tmp->left=new AvlNode<Comparable>(x,nullptr,nullptr);
                balance(tmp);
                break;
            }
            tmp=tmp->left;
        }
        else
        {
            if(tmp->right==nullptr)
            {
                tmp->right=new AvlNode<Comparable>(x,nullptr,nullptr);
                balance(tmp);
                break;
            }
            tmp=tmp->right;
        }
    }
    while(tmp!=t&&tmp!=nullptr)
    {
        AvlNode<Comparable> *last=t;
        while(!(last->left==tmp||last->right==tmp))
        {
            if(x<last->element)
            {
                last=last->left;
            }
            else
            {
                last=last->right;
            }
        }
        balance(last);
        tmp=last;
    }
}
template <typename Comparable>
void rotateWithLeftChild(AvlNode<Comparable> *&k2)
{
    AvlNode<Comparable> *k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->left),k2->height)+1;
    k2=k1;
}
template <typename Comparable>
void rotateWithRightChild(AvlNode<Comparable> *&k1)
{
    AvlNode<Comparable> *k2=k1->right;
    k1->right=k2->left;
    k2->left=k1;
    k1->height=max(height(k1->left),height(k1->right))+1;
    k2->height=max(height(k2->right),k1->height)+1;
    k1=k2;
}
template <typename Comparable>
void doubleWithLeftChild(AvlNode<Comparable> *&k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}
template <typename Comparable>
void doubleWithRightChild(AvlNode<Comparable> *&k1)
{
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}
static const int ALLOWED_IMBALANCE=1;
template <typename Comparable>
void balance(AvlNode<Comparable> *&t)
{
    if(t==nullptr)
    {
        return;
    }
    if(height(t->left)-height(t->right)>ALLOWED_IMBALANCE)
    {
        if(height(t->left->left)>=height(t->left->right))
        {
            rotateWithLeftChild(t);
        }
        else
        {
            doubleWithLeftChild(t);
        }
    }
    else if(height(t->right)-height(t->left)>ALLOWED_IMBALANCE)
    {
        if(height(t->right->right)>=height(t->right->left))
        {
            rotateWithRightChild(t);
        }
        else
        {
            doubleWithRightChild(t);
        }
    }
    t->height=max(height(t->left),height(t->right))+1;
}
template <typename Comparable>
AvlNode<Comparable>* findMin(AvlNode<Comparable> *&t);
template <typename Comparable>
void remove(const Comparable &x,AvlNode<Comparable> *&t)
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
        AvlNode *oldNode=t;
        t=(t->left!=nullptr)?t->left:t->right;
        delete oldNode;
    }
    balance(t);
}
template <typename Comparable>
int check(AvlNode<Comparable> *&t)
{
    if(t==nullptr)
    {
        return -1;
    }
    if(height(t)!=max(check(t->left),check(t->right))+1)
    {
        return -1;
    }
    return height(t);
}