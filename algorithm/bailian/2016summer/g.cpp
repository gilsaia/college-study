#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct treenode{
    treenode *left,*right;
    char name;
};
string middle,frontorder;
treenode * construct(int ms,int me,int fs,int fe){
    treenode *tmp=new treenode();
    tmp->left=nullptr,tmp->right=nullptr;
    tmp->name=middle[ms];
    if((me-ms)==1){
        return tmp;
    }
    int root=frontorder.find(middle[ms]);
    int len=root-fs;
    if(len!=0){
        tmp->left=construct(ms+1,ms+1+len,fs,root);
    }
    if(fe!=(root+1)){
        tmp->right=construct(ms+len+1,me,root+1,fe);
    }
    return tmp;
}
void output(treenode *cur){
    if(cur->left!=nullptr){
        output(cur->left);
    }
    if(cur->right!=nullptr){
        output(cur->right);
    }
    cout<<cur->name;
}
int main(){
    while(cin>>middle){
        cin>>frontorder;
        treenode *cur=construct(0,middle.length(),0,frontorder.length());
        output(cur);
        cout<<endl;
    }
    return 0;
}