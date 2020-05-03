#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string decode[22];
int main(){
    int n;
    string input;
    cin>>n>>input;
    int curline=0,dir=0;
    for(int i=0;i<input.length();++i){
        decode[curline]+=input[i];
        if(dir){
            if(curline==0){
                dir=0;
            }else{
                --curline;
            }
        }else{
            if(curline==(n-1)){
                dir=1;
            }else{
                ++curline;
            }
        }
    }
    for(int i=0;i<n;++i){
        cout<<decode[i];
    }
    cout<<endl;
    return 0;
}