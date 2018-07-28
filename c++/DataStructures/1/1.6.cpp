#include<string>
#include<iostream>
using namespace std;
void permute(const string& str)
{
    int n=str.size();
    permute(str,0,n);
}
void permute(const string& str,int low,int high)
{
    if(low==high)
    {
        cout<<str<<endl;
        return;
    }
    int num=low;
    for(int i=low;i<high;i++)
    {
        string toprint=str;
        char temp=toprint[num];
        toprint[num]=toprint[i];
        toprint[i]=temp;
        permute(toprint,low+1,high);
        temp=toprint[num];
        toprint[num]=toprint[i];
        toprint[i]=temp;
    }
    return;
}