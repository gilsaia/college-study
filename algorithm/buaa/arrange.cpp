#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int sou[120];
struct node{
    int data;
    node *left,*right;
    ~node(){
        if(this->left!=nullptr){
            delete left;
        }
        if(this->right!=nullptr){
            delete right;
        }
    }
};
node * findnode(int left,int right){
    if(left==right){
        return nullptr;
    }
    int num=right-left;
    int hei=1;
    while(num>=((1<<hei)-1)){
        ++hei;
    }
    --hei;
    int shrink=min(num-(1<<hei)+1,1<<(hei-1));
    int leftnum=(1<<(hei-1))-1+shrink;
    node *par=new node();
    par->data=sou[left+leftnum];
    par->left=findnode(left,left+leftnum);
    par->right=findnode(left+leftnum+1,right);
    return par;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&sou[i]);
    }
    sort(sou,sou+n);
    node *par=findnode(0,n);
    queue<node *> que;
    que.push(par);
    while(!que.empty()){
        node *tmp=que.front();
        que.pop();
        printf("%d ",tmp->data);
        if(tmp->left!=nullptr){
            que.push(tmp->left);
        }
        if(tmp->right!=nullptr){
            que.push(tmp->right);
        }
    }
    printf("\n");
    delete par;
    return 0;
}