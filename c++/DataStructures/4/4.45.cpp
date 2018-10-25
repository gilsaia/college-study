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
bool similar(AvlNode<Comparable> *left,AvlNode<Comparable> *right)
{
    if(left==nullptr&&right==nullptr)
    {
        return 1;
    }
    if(left==nullptr||right==nullptr)
    {
        return 0;
    }
    if(similar(left->left,right->left)&&similar(left->right,right->right))
    {
        return 1;
    }
    return 0;
}