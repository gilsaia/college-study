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
AvlNode<Comparable> *deletetree(AvlNode<Comparable> *&t)
{
    if(t->left==nullptr&&t->right==nullptr)
    {
        delete t;
        return nullptr;
    }
    t->left=deletetree(t->left);
    t->right=deletetree(t->right);
    return t;
}