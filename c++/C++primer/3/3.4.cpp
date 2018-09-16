#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
using std::endl;
int main()
{
    string a,b;
    cin>>a>>b;
    if(a!=b)
    {
        cout<<(a>b?a:b)<<endl;
    }
    else
    {
        cout<<a<<endl;
    }
    /*if(a.size()!=b.size())
    {
        cout<<(a.size()>b.size()?a:b)<<endl;
    }
    else
    {
        cout<<a<<endl;
    }*/
    return 0;
}