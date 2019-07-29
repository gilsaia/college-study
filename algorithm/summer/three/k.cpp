#include<iostream>
#include<string>
using namespace std;
int main()
{
    char ope;
    cin>>ope;
    if(ope=='E')
    {
        string encode;
        cin>>encode;
        string output;
        int nowsize=1;
        char nowope=encode[0];
        for(int i=1;i<encode.size();++i)
        {
            if(encode[i]==nowope)
            {
                ++nowsize;
            }
            else
            {
                output+=nowope;
                output+=('0'+nowsize);
                nowsize=1;
                nowope=encode[i];
            }
        }
        output+=nowope;
        output+=('0'+nowsize);
        cout<<output;
    }
    else
    {
        string decode;
        cin>>decode;
        string output;
        for(int i=0;i<decode.size();i+=2)
        {
            char tmp=decode[i];
            int size=decode[i+1]-'0';
            for(int j=0;j<size;++j)
            {
                output+=tmp;
            }
        }
        cout<<output;
    }
    return 0;
}