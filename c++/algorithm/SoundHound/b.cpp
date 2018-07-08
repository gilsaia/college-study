#include<iostream>
#include<string>
using namespace std;
int main()
{
    string dat;
    int n;
    cin>>dat>>n;
    string temp;
    temp+=dat[0];
    int t=n;
    while(t<dat.size())
    {
        temp+=dat[t];
        t+=n;
    }
    cout<<temp;
    return 0;
}