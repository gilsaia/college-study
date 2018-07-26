#include<iostream>
#include<string>
using namespace std;
int main()
{
    string in;
    cin>>in;
    int ans=0;
    for(int i=0;i<in.size();i+=3)
    {
        if(in[i]!='P')
        {
            ans++;
        }
        if(in[i+1]!='E')
        {
            ans++;
        }
        if(in[i+2]!='R')
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}