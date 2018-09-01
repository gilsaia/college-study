//折半查找题···似乎C++stl的lowerbound有一点小问题有时候会找错···然而map的好像就可以了···也不知道什么鬼操作···实在累了不想管了···
#include<stdio.h>
#include<algorithm>
#include<utility>
#include<cmath>
#include<map>
using namespace std;
int N;
typedef long long LL;
long long num[40];
const long long INF=1e13;
long long Abs(long long a)
{
    if(a<0)
    {
        a=-a;
    }
    return a;
}
int main()
{
    while(scanf("%d",&N))
    {
        if(N==0)
        {
            break;
        }
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&num[i]);
        }
        int n2=N/2;
        map<LL, int> M;
        map<LL, int>::iterator it;
        pair<LL, int> ans(Abs(num[0]), 1);

        for(int i=1; i<1<<(N/2); i++)
        {
            LL sum = 0;int cnt = 0;
            for(int j=0; j<(N/2); j++)
            {
                if((i>>j)&1)
                {
                    sum += num[j];
                    cnt ++;
                }
            }
            ans = min(ans, make_pair(Abs(sum), cnt));///全部是前半部分的；
            if(M[sum])///更新cnt为小的；
                M[sum] = min(M[sum], cnt);
            else
                M[sum] = cnt;
        }

        for(int i=1; i<1<<(N-N/2); i++)
        {
            LL sum = 0;int cnt = 0;
            for(int j=0; j<(N-N/2); j++)
            {
                if((i>>j)&1)
                {
                    sum += num[j+N/2];
                    cnt ++;
                }
            }
            ans = min(ans, make_pair(Abs(sum), cnt));///全部是后半部分的；

            it = M.lower_bound(-sum);///找到第一个大于-sum的位置，然后取两种情况的最小值；

            if(it != M.end())
                ans = min(ans, make_pair(Abs(sum+it->first), cnt+it->second));
            if(it != M.begin())
            {
                it--;
                ans = min(ans, make_pair(Abs(sum+it->first), cnt+it->second));
            }
        }
        printf("%lld %d\n",ans.first,ans.second);
    }
    return 0;
}