#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll modpow(ll x,ll n)
{
    ll res=1;
    while(n>0)
    {
        if(n&1)
        {
            res=res*x%MOD;
        }
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}
int main()
{
    long long a,k;
    string at;
    cin>>at;
    scanf("%lld",&k);
    vector<ll> sav;
    ll pos=0;
    pos=at.size();
    for(int i=0;i<at.size();++i)
    {
        if(at[i]=='0'||at[i]=='5')
        {
            sav.push_back(i);
        }
    }
    long long suan=0,down=0,up=0;
    down=modpow(2,pos)-1;
    down=modpow(down,MOD-2);
    up=modpow(2,pos*k)-1;
    suan=up*down;
    suan%=MOD;
    ll res=0;
    for(int i=0;i<sav.size();++i)
    {
        res+=modpow(2,sav[i]);
        res%=MOD;
    }
    res*=suan;
    res%=MOD;
    printf("%lld\n",res);
    return 0;
}