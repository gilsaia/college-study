#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int ans[11]={0,0,1,3,11,53,309,2119,16687,148329,1468457};
int res[120];
int main()
{
    int t,n;
    int size=0;
    scanf("%d",&t);
    while(size<t)
    {
        scanf("%d",&n);
        int num=0;
        for(int i=1;i<=n;++i)
        {
            if(n%i==0)
            {
                ++num;
            }
        }
        res[size++]=ans[num];
    }
    for(int i=0;i<t;++i)
    {
        cout<<res[i];
        if(i!=t-1)
        {
            cout<<endl;
        }
    }
    return 0;
}