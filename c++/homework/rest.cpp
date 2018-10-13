#include<iostream>
using std::cout;
using std::endl;
void print(int flag,int num)
{
    if(flag<1<<num)
    {
        int temp=flag;
        for(int i=0;i<26;++i)
        {
            if(temp&1)
            {
                cout<<(char)('a'+i);
            }
            temp>>=1;
        }
        cout<<endl;
        print(flag+1,num);
    }
}
int main()
{
    print(1,5);
    return 0;
}