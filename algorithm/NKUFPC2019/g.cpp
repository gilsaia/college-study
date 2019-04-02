#include<cstdio>
#include<algorithm>
#include<map>
#include<utility>
using namespace std;
typedef long long ll;
const ll MAXN=0xfffffffffffffff;
const ll MINN=-MAXN;
ll bits[100020],m;
ll sum(int i)
{
    ll s=0;
    while(i>0)
    {
        s+=bits[i];
        i-=i&-i;    
    }
    return s;
}
void add(int i,ll x)
{
    while(i<=(m+1))
    {
        bits[i]+=x;
        i+=i&-i;    
    }
}
struct solider
{
    ll pos;
    int belong;
};
solider warrars[100020];
multimap<ll,int> legion[100020];
int main()
{
    int n;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld%d",&warrars[i].pos,&warrars[i].belong);
        pair<ll,int> tmp(warrars[i].pos,i);
        legion[warrars[i].belong].insert(tmp);
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;++i)
    {
        int num;
        scanf("%d",&num);
        switch (num)
        {
            case 1:
            {
                int k;
                ll x;
                scanf("%d%lld",&k,&x);
                int belong=warrars[k].belong;
                ll nowpos=warrars[k].pos;
                auto it=legion[belong].find(nowpos);
                if(it->second!=k)
                {
                    ++it;
                }
                legion[belong].erase(it);
                warrars[k].pos+=x;
                pair<ll,int> tmp(warrars[k].pos,k);
                legion[belong].insert(tmp);
                break;
            }
            case 2:
            {
                int k,c;
                scanf("%d%d",&k,&c);
                int lastbelong=warrars[k].belong;
                ll nowpos=warrars[k].pos;
                ll legionpos=sum(lastbelong),newlegionpos=sum(c);
                ll newpos=nowpos+legionpos-newlegionpos;
                auto it=legion[lastbelong].find(nowpos);
                while(it->second!=k)
                {
                    ++it;
                }
                legion[lastbelong].erase(it);
                pair<ll,int> tmp(newpos,k);
                legion[c].insert(tmp);
                warrars[k].belong=c;
                warrars[k].pos=newpos;
                break;
            }
            case 3:
            {
                int l,r;
                ll x;
                scanf("%d%d%lld",&l,&r,&x);
                add(l,x);
                add(r+1,-x);
                break;
            }
            case 4:
            {
                int l,r;
                scanf("%d%d",&l,&r);
                ll minpos=MAXN,maxpos=MINN,ans=0;
                for(int i=l;i<=r;++i)
                {
                    auto it=legion[i].begin();
                    if(it==legion[i].end())
                    {
                        continue;
                    }
                    ll factmin=it->first+sum(i);
                    if(maxpos!=MINN)
                    {
                        ans=max(ans,abs(maxpos-factmin));
                    }
                    it=legion[i].end();
                    --it;
                    ll factmax=it->first+sum(i);
                    if(minpos!=MAXN)
                    {
                        ans=max(ans,abs(factmax-minpos));
                    }
                    minpos=min(minpos,factmin);
                    maxpos=max(maxpos,factmax);
                }
                printf("%lld\n",ans);
                break;
            }
            default:
                break;
        }
    }
    return 0;
}