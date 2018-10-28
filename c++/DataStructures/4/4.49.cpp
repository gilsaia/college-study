template <typename Comparable>
struct AvlNode
{
    Comparable element;
    AvlNode *left;
    AvlNode *right;
    int height;
    bool isorderleft,isorderright;
    int x,y;
    AvlNode(const Comparable &ele,AvlNode *lt,AvlNode *rt,int h=0,bool orl=1,bool orr=true)
    :element{ele},left{lt},right{rt},height{h},isorderleft{orl},isorderright{orr}{}
    AvlNode(Comparable &&ele,AvlNode *lt,AvlNode *rt,int h=0,bool orl=1,bool orr=true)
    :element{std::move(ele)},left{lt},right{rt},height{h},isorderleft{orl},isorderright{orr}{}
};
template <typename Comparable>
bool insert(AvlNode<Comparable> *root,Comparable &x)
{
    if(x==root->element)
    {
        return true;
    }
    if(x<root->element)
    {
        if(root->isorderleft==0)
        {
            insert(root->left,x);
        }
        else
        {
            AvlNode<Comparable> *tmp=new AvlNode<Comparable>(x,root->left,root,root->height+1,1,1);
            root->left=tmp;
            root->isorderleft=0;
            return true;
        }
    }
    else
    {
        if(root->isorderright==0)
        {
            insert(root->right,x);
        }
        else
        {
            AvlNode<Comparable> *tmp=new AvlNode<Comparable>(x,root,root->right,root->height+1,1,1);
            root->right=tmp;
            root->isorderright=0;
            return true;
        }
    }
}
