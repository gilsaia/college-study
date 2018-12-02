#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int INF=1e9+7;
int main()
{
    int t,n,x,y,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&x,&y,&d);
        if(abs(y-x)%d==0)
        {
            printf("%d\n",abs(y-x)/d);
            continue;
        }
        int ans=INF;
        if((y-1)%d==0)
        {
            int tmp=(y-1)/d;
            tmp+=(x-1)/d;
            if((x-1)%d!=0)
            {
                tmp++;
            }
            ans=min(ans,tmp);
        }
        if((n-y)%d==0)
        {
            int tmp=(n-y)/d;
            tmp+=(n-x)/d;
            if((n-x)%d!=0)
            {
                tmp++;
            }
            ans=min(ans,tmp);
        }
        if(ans!=INF)
        {
            printf("%d\n",ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}