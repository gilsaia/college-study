#include<cstdio>
#include<algorithm>
#include<map>
#include<utility>
using namespace std;
typedef long long ll;
map<pair<ll,ll>,double> memo;
int r;
ll k;
double p,rest;
double dp(ll l,ll r)
{
    if(memo.find(make_pair(l,r))!=memo.end())
    {
        return memo[make_pair(l,r)];
    }
    if(l==0)
    {
        double tmp=p*dp(0,r>>1);
        memo[make_pair(l,r)]=tmp;
        return tmp;
    }
    if(r==0)
    {
        double tmp=rest*dp(l>>1,0);
        memo[make_pair(l,r)]=tmp;
        return tmp;
    }
    if(!(l&1))
    {
        double tmp=p*dp(l>>1,r>>1);
        memo[make_pair(l,r)]=tmp;
        return tmp;
    }
    else
    {
        double tmp=p*(p*dp((l>>1)+1,(r>>1)-1)+rest*dp(l>>1,r>>1));
        memo[make_pair(l,r)]=tmp;
        return tmp;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lld%lf",&r,&k,&p);
        rest=1.0-p;
        memo.clear();
        ll num=1LL<<r;
        memo[make_pair(0,1)]=p;
        memo[make_pair(1,0)]=rest;
        ll left=k-1,right=num-k;
        if(p<0.5)
        {
            swap(left,right);
            swap(p,rest);
        }
        double res=dp(left,right);
        printf("%.6lf\n",res);
    }
    return 0;
}