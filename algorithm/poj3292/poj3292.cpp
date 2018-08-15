//这题折腾了好长时间···没有正确搞对题意···基本就是自己实现一个打表的事情···
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int isprime[1000010];
int save[1000010];
int main()
{
    for(int i=5;i<=1000001;i+=4)
    {
        for(int j=i;j<=1000001;j+=4)
        {
            long long mul=i;
            mul*=j;
            if(mul<=1000001)
            {
                if(isprime[i]==0&&isprime[j]==0)
                {
                    isprime[mul]=1;
                }
                else
                {
                    isprime[mul]=-1;
                }
            }
            else
            {
                break;
            }
        }
    }
    int ans=0;
    for(int i=5;i<=1000001;i+=4)
    {
        if(isprime[i]==1)
        {
            ans++;
        }
        save[i]=ans;
    }
    int t;
    while(cin>>t)
    {
        if(t==0)
        {
            break;
        }
        cout<<t<<" ";
        cout<<save[t]<<endl;
    }
    return 0;
}