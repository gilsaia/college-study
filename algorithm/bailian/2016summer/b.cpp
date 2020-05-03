#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string tmp;
    bool first=1;
    getline(cin,tmp);
    int lastindex=0;
    for(int i=0;i<tmp.length();++i){
        if(tmp[i]==' '){
            reverse(tmp.begin()+lastindex,tmp.begin()+i);
            int j=i+1;
            while(j<tmp.length()&&tmp[j]==' '){
                ++j;
            }
            lastindex=j;
            i=j;
        }
    }
    reverse(tmp.begin()+lastindex,tmp.end());
    cout<<tmp<<endl;
    return 0;
}