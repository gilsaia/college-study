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
AvlNode<Comparable> * createperfect(Comparable num,Comparable ext=0)
{
    AvlNode<Comparable> *t;
    if(ext==0)
    {
        t=new AvlNode<Comparable>((num+1)/2,nullptr,nullptr);
        t->left=createperfect(t->element,(-1)*t->element/2);
        t->right=createperfect(t->element,t->element/2);
        return t;
    }
    if(ext==1||ext==-1)
    {
        t=new AvlNode<Comparable>(num+ext,nullptr,nullptr);
        return t;
    }
    t=new AvlNode<Comparable>(num+ext,nullptr,nullptr);
    t->left=createperfect(t->element,ext/2);
    t->right=createperfect(t->element,ext/2);
    return t;
}