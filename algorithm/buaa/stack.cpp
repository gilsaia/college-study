//题目描述似乎与样例二输出矛盾 题目描述对同一函数存在多个相同最深路径时只输出执行顺序最早的路径 而样例二的输出对同一函数mysin输出了两次同样深度的路径 似乎有矛盾
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<vector>
using namespace std;
struct node{
    string name;
    node *par;
};
int maxhei,hei;
node *cur;
map<string,vector<string>> callcount;
queue<node *> *que;
int main(){
    int opera;
    cur=new node();
    maxhei=0;
    hei=0;
    string name;
    que=new queue<node *>;
    while(cin>>opera){
        if(opera){
            cin>>name;
            node *tmp=new node();
            tmp->name=name;
            tmp->par=cur;
            ++hei;
            if(hei>maxhei){
                delete que;
                que=new queue<node *>;
                que->push(tmp);
                maxhei=hei;
            }else if(hei==maxhei){
                que->push(tmp);
            }
            if(cur->name!=""){
                callcount[name].push_back(cur->name);
            }
            cur=tmp;
        }else{
            cur=cur->par;
            --hei;
        }
    }
    stack<string> path;
    set<string> nameset;
    set<string> unifun;
    string funname;
    while(!que->empty()){
        node *tmp=que->front();
        que->pop();
        funname=tmp->name+" ";
        // cout<<tmp->name<<" ";
        name=tmp->name;
        while(tmp->name!=""){
            path.push(tmp->name);
            tmp=tmp->par;
        }
        funname+=path.top();
        // cout<<path.top();
        path.pop();
        while(!path.empty()){
            funname+="-";
            funname+=path.top();
            // cout<<"-"<<path.top();
            path.pop();
        }
        funname+=" ";
        // cout<<" ";
        nameset.clear();
        for(unsigned int i=0;i<callcount[name].size();++i){
            nameset.insert(callcount[name][i]);
        }
        funname+=to_string(nameset.size())+" "+to_string(callcount[name].size());
        if(unifun.find(funname)!=unifun.end()){
            continue;
        }
        unifun.insert(funname);
        cout<<funname<<endl;
        // cout<<nameset.size()<<" "<<callcount[name].size()<<endl;
    }
    return 0;
}