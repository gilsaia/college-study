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
bool checkisomorphic(AvlNode<Comparable> *left,AvlNode<Comparable> *right)
{
    if(left==nullptr&&right==nullptr)
    {
        return true;
    }
    else if(left!=nullptr&&right!=nullptr)
    {
        if(left->element==right->element)
        {
            if((checkisomorphic(left->left,right->left)&&checkisomorphic(left->right,right->right))||(checkisomorphic(left->left,right->right)&&checkisomorphic(left->right,right->left))
            {
                return true;
            }
        }
    }
    return false;
}