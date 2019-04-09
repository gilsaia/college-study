#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int digit1[120],digit2[120];
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;++i)
    {
        string input;
        cin>>input;
        for(int j=0;j<input.size();++j)
        {
            digit1[j]=digit2[j]=0;
        }
        for(int j=0;j<input.size();++j)
        {
            if(input[j]=='4')
            {
                digit1[j]=3;
                digit2[j]=1;
            }
            else
            {
                digit1[j]=input[j]-'0';
            }
        }
        string output1,output2;
        bool output2begin=false;
        for(int j=0;j<input.size();++j)
        {
            output1+=(digit1[j]+'0');
            if(!output2begin)
            {
                if(digit2[j]!=0)
                {
                    output2+=('0'+digit2[j]);
                    output2begin=true;
                }
            }
            else
            {
                output2+=('0'+digit2[j]);
            }
        }
        cout<<"Case #"<<i<<": "<<output1<<" "<<output2<<endl;
    }
    return 0;
}