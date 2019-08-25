#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string tmp;
    while(cin>>tmp)
    {
        int left=0,right=0;
        for(int i=0;i<tmp.size();++i)
        {
            if(tmp[i]=='(')
            {
                left++;
            }
            else
            {
                right++;
            }
        }
        if(left==right)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}