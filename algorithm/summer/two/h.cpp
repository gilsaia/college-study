#include<iostream>
#include<algorithm>
using namespace std;
int seq[1020];
struct node
{
    int val;
    node *right,*left;
    node()
    {
        val=0;
        right=left=NULL;
    }
};
node * insert(node *root,int val)
{
    if(root==NULL)
    {
        root=new node;
        root->val=val;
        return root;
    }
    if(val>root->val)
    {
        root->right=insert(root->right,val);
    }
    else
    {
        root->left=insert(root->left,val);
    }
    return root;
}
void find(int val,node *root)
{

    if(val==root->val)
    {
        return;
    }
    if(val>root->val)
    {
        cout<<'W';
        find(val,root->right);
    }
    else
    {
        cout<<'E';
        find(val,root->left);
    }
    return;
}
void remove(node *root)
{
    if(root==NULL)
    {
        return;
    }
    remove(root->left);
    remove(root->right);
    delete root;
    return;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        node *root=NULL;
        for(int i=0;i<n;++i)
        {
            int tmp;
            cin>>tmp;
            root=insert(root,tmp);
        }
        int q;
        cin>>q;
        for(int i=0;i<q;++i)
        {
            int val;
            cin>>val;
            find(val,root);
            cout<<endl;
        }
        remove(root);
    }
    return 0;
}