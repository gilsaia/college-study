#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
    string tmp;
    set<string> rep;
    int res=1;
    while(cin>>tmp)
    {
        if(rep.find(tmp)!=rep.end())
        {
            res=0;
        }
        rep.insert(tmp);
    }
    if(res==1)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    return 0;
}