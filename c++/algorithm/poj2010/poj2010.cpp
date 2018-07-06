//优先队列的问题，将奶牛们按分数排序后将能取中位数部分先空出，根据左右算出左侧和右侧学费最小值，然后根据中间条件利用优先队列逐渐扫描
//最后第一个学费满足条件的即为所求(注意N为1的情况可能造成队列为空)
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
struct cow
{
    int score,aid,left,right;
};
bool cmp(cow a,cow b)
{
    return a.score<b.score;
}
cow dat[100010];
int main()
{
    int N,C,F;
    scanf("%d%d%d",&N,&C,&F);
    for(int i=1;i<=C;i++)
    {
        scanf("%d%d",&dat[i].score,&dat[i].aid);
    }
    sort(dat+1,dat+1+C,cmp);
    if(N>1)
    {
        int sum=0;
        priority_queue<int> mon;
        for(int i=1;i<=N/2;i++)
        {
            sum+=dat[i].aid;
            mon.push(dat[i].aid);
        }
        for(int i=N/2+1;i<=C-N/2;i++)
        {
            dat[i].left=sum;
            int temp=mon.top();
            if(dat[i].aid<temp)
            {
                mon.pop();
                sum=sum-temp+dat[i].aid;
                mon.push(dat[i].aid);
            }
        }
        priority_queue<int> mon2;
        sum=0;
        for(int i=C;i>=C-N/2+1;i--)
        {
            sum+=dat[i].aid;
            mon2.push(dat[i].aid);
        }
        for(int i=C-N/2;i>=N/2+1;i--)
        {
            dat[i].right=sum;
            int temp=mon2.top();
            if(dat[i].aid<temp)
            {
                mon2.pop();
                sum=sum-temp+dat[i].aid;
                mon2.push(dat[i].aid);
            }
        }
    }
    int ans=-1;
        for(int i=C-N/2;i>=N/2+1;i--)
        {
            if((dat[i].aid+dat[i].left+dat[i].right)<=F)
            {
                ans=dat[i].score;
                break;
            }
        }
        printf("%d\n",ans);
        return 0;
}