#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;++i)
        {
            int tmp;
            scanf("%d",&tmp);
            sum+=tmp;
        }
        int ans=sum/n;
        if(sum%n)
        {
            ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}