//最基本的检查素数题，直接埃氏筛法筛完存起来就好···哦对记得存素数的数组别开太小··
#include<iostream>
using namespace std;
bool isprime[10000010];
int prime[1000000];
const int MAX=1e7;
int main()
{
    int en=0;
    isprime[0]=isprime[1]=1;
    for(int i=2;i<=MAX;i++)
    {
        if(!isprime[i])
        {
            prime[en]=i;
            en++;
            for(int j=i+i;j<=MAX;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
    int t;
    while(cin>>t)
    {
        int ans=0;
        for(int i=0;i<en;i++)
        {
            if(prime[i]>t)
            {
                break;
            }
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}