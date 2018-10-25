#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int num[240];
int main()
{
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    int flag=1;
    for(int i=0;i<s.size();++i)
    {
        for(int j=s.size()-1;j>=i;--j)
        {
            int pan=0;
            string tmp=s.substr(i,j-i+1);
            memset(num,0,sizeof(num));
            int len=tmp.size();
            for(int t=0;t<len;++t)
            {
                num[tmp[t]]++;
            }
            for(int t=0;t<150;++t)
            {
                if(num[t]>len/2)
                {
                    pan=1;
                    break;
                }
            }
            if(pan==0)
            {
                printf("YES\n");
                cout<<tmp<<endl;
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
    if(flag)
    {
        printf("NO\n");
    }
    return 0;
}