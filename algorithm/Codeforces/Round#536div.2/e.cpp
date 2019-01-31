#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll timeline[100020];
int nextint[100020];
struct env
{
    ll start,end,d,coin;
    bool operator<(env &rhs)
    {
        if(start==rhs.start)
        {
            if(coin==rhs.coin)
            {
                return d>rhs.d;
            }
            return coin>rhs.coin;
        }
        return start<rhs.start;
    }
};
env envlope[100020];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;++i)
    {
        scanf("%I64d%I64d%I64d%I64d",&envlope[i].start,&envlope[i].end,&envlope[i].d,&envlope[i].coin);
    }
    sort(envlope,envlope+k);
    for(int i=k-1;i>=0;--i)
    {
        ll tmp=envlope[i].end;
        while(tmp!=(envlope[i].start-1))
        {
            if(timeline[tmp]<=timeline[tmp+envlope[i].d]+envlope[i].coin)
            {
                nextint[tmp]=i;
                timeline[tmp]=timeline[tmp+envlope[i].d]+envlope[i].coin;
            }
            tmp--;
        }
    }
    vector<int> seq;
    seq.push_back(1);
}
