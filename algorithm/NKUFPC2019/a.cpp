#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll save[1000020];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>save[i];
    }
    sort(save,save+n);
    ll ans=0,num=n;
    for(int i=0;i<n;++i)
    {
        ans+=save[i]*num--;
    }
    cout<<ans<<endl;
    return 0;
}