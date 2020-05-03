#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int maxm[3]={10,7,5};
struct water{
    int num[3];
    string op;
};
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    queue<water> que;
    water tmp;
    tmp.num[0]=x,tmp.num[1]=y,tmp.num[2]=z;
    que.push(tmp);
    while(!que.empty()){
        water tmp=que.front();
        if(tmp.num[0]==3&&tmp.num[1]==4&&tmp.num[2]==5){
            cout<<tmp.op<<endl;
            break;
        }
        water op1=
    }
}