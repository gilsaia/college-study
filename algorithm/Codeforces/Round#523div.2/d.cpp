#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct TVS
{
    int starttime,endtime;
};
bool operator<(TVS lhs,TVS rhs)
{
    return lhs.endtime>rhs.endtime;
}
struct line
{
    int l,r;
    bool operator<(line &rhs)
    {
        if(l==rhs.l)
        {
            return r<rhs.r;
        }
        return l<rhs.l;
    }
}lines[100020];
typedef long long ll;
const ll MOD=1e9+7;
int main()
{
    ll n,x,y;
    scanf("%I64d%I64d%I64d",&n,&x,&y);
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",&lines[i].l,&lines[i].r);
    }
    sort(lines,lines+n);
    priority_queue<TVS> tool;
    ll ans=0;
    for(int i=0;i<n;++i)
    {
        if(tool.empty())
        {
            TVS tmp;
            tmp.starttime=lines[i].l,tmp.endtime=lines[i].r;
            tool.push(tmp);
        }
        else
        {
            TVS tmp=tool.top();
            tool.pop();
            ll cmp=lines[i].l-tmp.endtime;
            cmp*=y;
            if(lines[i].l<=tmp.endtime)
            {
                tool.push(tmp);
                TVS toin;
                toin.starttime=lines[i].l,toin.endtime=lines[i].r;
                tool.push(toin);
            }
            else if(cmp<x)
            {
                tmp.endtime=lines[i].r;
                tool.push(tmp);
            }
            else
            {
                ll thesu=tmp.endtime-tmp.starttime;
                ans+=x+thesu*y;
                ans%=MOD;
                TVS toin;
                toin.starttime=lines[i].l,toin.endtime=lines[i].r;
                tool.push(toin);
            }
        }
    }
    while(!tool.empty())
    {
        TVS tmp=tool.top();
        tool.pop();
        ll thesu=tmp.endtime-tmp.starttime;
        ans+=x+thesu*y;
        ans%=MOD;
    }
    printf("%I64d\n",ans);
    return 0;
}