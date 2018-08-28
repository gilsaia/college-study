//一道巧妙的尺取法的题···本来数据中有负数是无法尺取的···但是取前缀和后因为所求关系是绝对值，所以前缀和排序相减是具有单调性的从而能够利用尺取法···
#include<stdio.h>
#include<utility>
#include<algorithm>
#include<cmath>
using namespace std;
const int INF=1e9;
pair<int,int> sum[100010];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k))
    {
        if(n==0&&k==0)
        {
            break;
        }
        sum[0]=make_pair(0,0);
        int tmp=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            tmp+=x;
            sum[i]=make_pair(tmp,i);
        }
        sort(sum,sum+n+1);
        for(int j=0;j<k;j++)
        {
            int t;
            scanf("%d",&t);
            int l=0,r=1,min=INF,ansl=0,ansr=0,ans=0;
            while(r<=n&&min)
            {
                int com=sum[r].first-sum[l].first;
                if(abs(com-t)<=min)
                {
                    min=abs(com-t);
                    ans=com;
                    ansl=sum[l].second;
                    ansr=sum[r].second;
                }
                if(com>t)
                {
                    l++;
                }
                if(com<t)
                {
                    r++;
                }
                if(l==r)
                {
                    r++;
                }
            }
            if(ansl>ansr)
            {
                swap(ansl,ansr);
            }
            printf("%d %d %d\n",ans,ansl+1,ansr);
        }        
    }
    return 0;
}