#include<algorithm>
using std::max;
typedef int Comparable;
struct AvlNode
{
    Comparable element;
    AvlNode *left;
    AvlNode *right;
    int height;
};
int height(AvlNode *t);
void rotateWithLeftChild(AvlNode *&k2)
{
    AvlNode *k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->left),k2->height)+1;
    k2=k1;
}
void rotateWithRightChild(AvlNode *&k1)
{
    AvlNode *k2=k1->right;
    k1->right=k2->left;
    k2->left=k1;
    k1->height=max(height(k1->left),height(k1->right))+1;
    k2->height=max(height(k2->right),k1->height)+1;
    k1=k2;
}
void doubleWithLeftChild(AvlNode *&k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}
void doubleWithRightChild(AvlNode *&k1)
{
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}