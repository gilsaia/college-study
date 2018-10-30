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
int check(AvlNode<Comparable> *&t)
{
    if(t==nullptr)
    {
        return -1;
    }
    if(t->element>check(t->left)&&(check(t->right)==-1||t->element<check(t->right)))
    {
        return t->element;
    }
    return 0;
}