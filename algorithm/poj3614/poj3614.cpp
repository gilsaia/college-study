//优先队列的问题，将奶牛和防晒霜分别从大到小排好序后，对每个防晒霜满足其值小于奶牛最大值的放入优先队列
//优先队列按奶牛最小值从大到小的顺序排列后逐次取出最小值最大的(更小的有更大的选择范围)
//验证一下是否满足条件，满足则ans加一不满足则舍弃该牛(因这已是最大值的防晒霜该牛最小值仍大于其值说明以后的防晒霜都不满足)
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

struct cow
{
    int max,min;
    bool operator <(const cow& t)const
    {
        return min<t.min;
    }
};
struct lotion
{
    int SPF,num;
    bool operator <(const lotion& t)const
    {
        return SPF>t.SPF;
    }
};
lotion sun[3000];
bool cmp(cow a,cow b)
{
    if(a.max==b.max)
    {
        return a.min>b.min;
    }
    else
    {
        return a.max>b.max;
    }
}
cow cows[3000];
int main()
{
    int C,L;
    scanf("%d%d",&C,&L);
    for(int i=0;i<C;i++)
    {
        scanf("%d%d",&cows[i].min,&cows[i].max);
    }
    sort(cows,cows+C,cmp);
    for(int i=0;i<L;i++)
    {
        scanf("%d%d",&sun[i].SPF,&sun[i].num);
    }
    sort(sun,sun+L);
    int num=0,ans=0;
    priority_queue<cow> res;
    for(int i=0;i<L;i++)
    {
        while(num<C&&cows[num].max>=sun[i].SPF)
        {
            res.push(cows[num]);
            num++;
        }
        while(res.size()&&sun[i].num)
        {
            cow temp=res.top();
            res.pop();
            if(temp.min<=sun[i].SPF)
            {
                ans++;
                sun[i].num--;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}