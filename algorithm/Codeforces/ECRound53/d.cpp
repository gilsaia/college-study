#include<cstdio>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1e13;
ll cost[200050];
bool used[200050];
int main()
{
    int n,num=0;
    ll money,minc=INF,sum=0,ans=0;
    scanf("%d%I64d",&n,&money);
    priority_queue<pair<ll,int>> que;
    for(int i=0;i<n;++i)
    {
        scanf("%I64d",&cost[i]);
        minc=min(minc,cost[i]);
        que.push(make_pair(cost[i],i));
        sum+=cost[i];
        num++;
    }
    int flag=1;
    while(flag&&!que.empty())
    {
        if(money>=sum)
        {
            ans+=num*(money/sum);
            money=money%sum;
        }
        pair<ll,int> tmp=que.top();
        if(money<tmp.first)
        {
            used[tmp.second]=0;
            sum-=tmp.first;
            --num;
            que.pop();
        }
        else
        {
            for(int i=0;i<n;++i)
            {
                if(!used[i]&&money>=cost[i])
                {
                    money-=cost[i];
                    ans++;
                }
            }
        }
        if(money<minc)
        {
            flag=0;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}