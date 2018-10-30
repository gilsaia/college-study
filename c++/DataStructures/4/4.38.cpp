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
void checkx(AvlNode<Comparable> *root,int x=0)
{
    if(root==nullptr)
    {
        return;
    }
    checkx(root->left,x-1);
    root->x=x;
    checkx(root->right,x+1);
}