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
int countnum(AvlNode<Comparable> *&t)
{
    if(t==nullptr)
    {
        return 0;
    }
    else
    {
        return countnum(t->left)+countnum(t->right)+1;
    }
}
template <typename Comparable>
int countleaf(AvlNode<Comparable> *&t)
{
    if(t==nullptr)
    {
        return 0;
    }
    else if(t->left==nullptr&&t->right==nullptr)
    {
        return 1;
    }
    else
    {
        return countleaf(t->left)+countleaf(t->right);
    }
}
template <typename Comparable>
int countpoint(AvlNode<Comparable> *&t)
{
    if(t==nullptr)
    {
        return 0;
    }
    else if(t->left!=nullptr&&t->right!=nullptr)
    {
        return countpoint(t->left)+countpoint(t->right)+1;
    }
    else
    {
        return countpoint(t->left)+countpoint(t->right);
    }
}