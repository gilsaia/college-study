#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
using std::endl;
int main()
{
    string out,tmp;
    while(cin>>tmp)
    {
        out+=tmp;
        //out+=tmp+' ';
    }
    cout<<out;
    return 0;
}