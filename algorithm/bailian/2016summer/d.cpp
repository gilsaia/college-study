#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct dir{
    string name;
    vector<dir *> dirtree;
    vector<string> file;
    dir *root;
};
int num=1;
bool scanfile(){
    string tmp;
    cin>>tmp;
    if(tmp[0]=='#'){
        return true;
    }
    
}
int main(){
    while(true){
        string tmp;
        if(scanfile()){
            break;
        }
    }
}