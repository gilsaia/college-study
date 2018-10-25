template <typename Object>
struct TreeNode
{
    Object element;
    TreeNode *firstChild;
    TreeNode *nextSibling;
};
template <typename Object>
void Treecheck(TreeNode<Object> *root)
{
    if(root==nullptr)
    {
        return;
    }
    //cout<<root->element;
    Treecheck(root->nextSibling);
    Treecheck(root->firstChild);
}