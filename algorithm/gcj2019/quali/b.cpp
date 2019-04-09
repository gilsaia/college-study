#include<iostream>
#include<string>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int m=1;m<=T;++m)
    {
        int N;
        cin>>N;
        string result;
        cin>>result;
        for(int i=0;i<result.size();++i)
        {
            if(result[i]=='S')
            {
                result[i]='E';
            }
            else
            {
                result[i]='S';
            }
        }
        cout<<"Case #"<<m<<": "<<result<<endl;
    }
    return 0;
}