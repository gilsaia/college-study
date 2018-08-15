//不知道为啥算二分···看了半天不知道怎么搞···最后查了查题解发现大家算是贪心做的···排完序直接找就好了···注意答案会有负值所以求最大值初始值一定小心···
//至于排序的思路大概是这样
//假设已经是完美的排序了···那么相邻的两头牛如果交换位置那么只会相互影响，这时候将两种情况的最大值求出来因为假定开始的是完美排序所以开始的最大值要小于等于之后的最大值，由此可以得出排序依据就是力量和重量之和排序即可···
#include<stdio.h>
#include<algorithm>
using namespace std;
struct cow
{
    long long w,s;
};
bool cmp(cow a,cow b)
{
    return a.w+a.s>b.w+b.s;
}
cow mee[50020];
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%lld%lld",&mee[i].w,&mee[i].s);
    }
    sort(mee,mee+N,cmp);
    long long sum=0,maxm=-1000000000;
    for(int j=N-1;j>=0;j--)
    {
        long long temp=sum-mee[j].s;
        maxm=max(maxm,temp);
        sum+=mee[j].w;
    }
    printf("%d\n",maxm);
    return 0;
}