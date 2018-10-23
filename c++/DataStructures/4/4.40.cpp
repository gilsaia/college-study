#include<queue>
#include<iostream>
using std::ostream;
using std::cout;
using std::queue;
template <typename Comparable>
struct AvlNode
{
    Comparable element;
    AvlNode *left;
    AvlNode *right;
    int height;
    int x,y;
    AvlNode(const Comparable &ele,AvlNode *lt,AvlNode *rt,int h=0)
    :element{ele},left{lt},right{rt},height{h}{}
    AvlNode(Comparable &&ele,AvlNode *lt,AvlNode *rt,int h=0)
    :element{std::move(ele)},left{lt},right{rt},height{h}{}
};
template <typename Comparable>
void output(AvlNode<Comparable> *root,ostream &out=cout)
{
    queue<AvlNode<Comparable>*> que;
    que.push(root);
    while(!que.empty())
    {
        AvlNode<Comparable> *tmp=que.front();
        que.pop();
        out<<tmp->element;
        if(tmp->left!=nullptr)
        {
            que.push(tmp->left);
        }
        if(tmp->right!=nullptr)
        {
            que.push(tmp->right);
        }
    }
}