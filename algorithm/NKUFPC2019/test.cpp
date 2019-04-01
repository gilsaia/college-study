#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char *tmp;
    tmp=new char[100];
    cin>>tmp;
    int length=0,nowlength=0;
    char *find=tmp,*ans;
    while(*(find+1)!='\0')
    {
        if((*find)==(*(find+1)))
        {
            if((nowlength+1)>length)
            {
                ans=find;
                length=nowlength+1;
            }
            nowlength=0;
            find=find+1;
        }
        else
        {
            nowlength++;
            find=find+1;
        }   
    }
    if((nowlength+1)>length)
    {
        ans=find;
        length=nowlength+1;
    }
    for(int i=0;i<length;++i)
    {
        cout<<*(ans-length+i+1);
    }
    cout<<endl;
    return 0;
}