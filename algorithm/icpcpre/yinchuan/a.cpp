#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int> >v;

int main(){
    for(int i=0;i<1000;++i)v.emplace_back(make_pair(i,i<<1));
    for(auto p:v){
        cout<<p.first<<' '<<p.second<<endl;
    }
    return 0;
}
