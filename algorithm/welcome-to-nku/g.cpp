#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
set<ll>st;
int main()
{
    ll a,b;
    cin>>a>>b;
    ll n=(a+b);
    ll res=1e18;
    for(ll i=1;i*i<=n;i++){
        if(a%i==0) st.insert(a/i);
        if(b%i==0) st.insert(b/i);
        if(n%i==0){
            ll h=i;
            ll w=n/i;
            if(*st.begin()<=w){
                res=min(res,h*2+w*2);
            }
        }
    }
    cout<<res<<endl;
}
/*
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long long a,b,sum;
    scanf("%lld%lld",&a,&b);
    if(a>b)
    {
        long long tmp=a;
        a=b;
        b=tmp;
    }
    long long tofinda=sqrt(a);
    while(a%tofinda!=0)
    {
        --tofinda;
    }
    tofinda=a/tofinda;
    long long tofindb=sqrt(b);
    while(b%tofindb!=0)
    {
        --tofindb;
    }
    tofindb=b/tofindb;
    if(tofinda>tofindb)
    {
        tofinda=tofindb;
    }
    sum=a+b;
    long long tofind=sqrt(sum);
    while(1)
    {
        if(sum%tofind!=0)
        {
            --tofind;
            continue;
        }
        else
        {
            if(sum/tofind>=tofinda)
            {
                break;
            }
            else
            {
                --tofind;
                continue;
            }
        }
    }
    long long ans=(tofind+sum/tofind)*2;
    printf("%lld\n",ans);
    return 0;
}*/