#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=400020;
int pre[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        map<int,int> nowbuy;
        int n,k,d;
        scanf("%d%d%d",&n,&k,&d);
        int i;
        for(i=0;i<d;++i)
        {
            int tmp;
            scanf("%d",&tmp);
            pre[i]=tmp;
            nowbuy[tmp]++;
        }
        int ans=nowbuy.size();
        for(;i<n;++i)
        {
            int tmp;
            scanf("%d",&tmp);
            pre[i]=tmp;
            if(nowbuy[pre[i-d]]==1)
            {
                nowbuy.erase(pre[i-d]);
            }
            else
            {
                --nowbuy[pre[i-d]];
            }
            nowbuy[tmp]++;
            ans=min(ans,(int)nowbuy.size());
        }
        printf("%d\n",ans);
    }
    return 0;
}