#include<iostream>
using std::cout;
using std::ostream;
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
void output(AvlNode<Comparable> *root,Comparable k1,Comparable k2,ostream &out=cout)
{
    if(root==nullptr)
    {
        return;
    }
    if(root->element>k1)
    {
        output(root->left,k1,k2,out);
    }
    if(root->element>=k1&&root->element<=k2)
    {
        out<<root->element;
    }
    if(root->element<k2)
    {
        output(root->right,k1,k2,out);
    }
}