#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int num[320000];
int main()
{
    int n;
    ll ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    int head=0,tail=n-1;
    for(int i=0;i<n/2;++i)
    {
        ll tmp=num[head]+num[tail];
        ans+=tmp*tmp;
        ++head,--tail;
    }
    cout<<ans<<endl;
    return 0;
}