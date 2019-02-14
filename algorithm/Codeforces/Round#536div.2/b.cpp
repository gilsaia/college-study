#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
#include<utility>
#include<functional>
using namespace std;
typedef long long ll;
ll dish[100050],cost[100050];
int main()
{
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    ll n,m;
    scanf("%I64d%I64d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%I64d",&dish[i]);
    }
    for(int i=1;i<=n;++i)
    {
        pair<int,int> tmp;
        tmp.second=i;
        scanf("%d",&tmp.first);
        cost[i]=tmp.first;
        que.push(tmp);
    }
    for(int i=0;i<m;++i)
    {
        ll ans=0;
        ll wantdish,num=0;
        scanf("%I64d%I64d",&wantdish,&num);
        while(num!=0)
        {
            if(dish[wantdish]>=num)
            {
                dish[wantdish]-=num;
                ans+=num*cost[wantdish];
                num=0;
                break;
            }
            else
            {
                ll numtmp=dish[wantdish];
                dish[wantdish]=0;
                ans+=numtmp*cost[wantdish];
                num-=numtmp;
                while(!que.empty())
                {
                    if(dish[que.top().second]!=0)
                    {
                        wantdish=que.top().second;
                        break;
                    }
                    else
                    {
                        que.pop();
                    }
                }
                if(que.empty())
                {
                    ans=0;
                    num=0;
                    break;
                }
            }     
        }
        printf("%I64d\n",ans);
    }
    return 0;
}