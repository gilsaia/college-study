#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int res=0;
    int first,end;
    int isfirst=1;
    for(int i=0;i<a.size();++i)
    {
        if(a[i]!=b[i])
        {
            if(isfirst)
            {
                first=i;
                isfirst=0;
            }
            end=i;
        }
    }
    int can=1;
    for(int i=first;i<=end;++i)
    {
        if(a[i]!=b[end-i+first])
        {
            can=0;
            break;
        }
    }
    if(can)
    {
        res=1;
        for(int i=1;(first-i)>=0&&(end+i)<a.size();++i)
        {
            if(a[first-i]==a[end+i])
            {
                ++res;
                continue;
            }
            break;
        }
    }
    cout<<res<<endl;
    return 0;
}