//emmmmmmmm·····
#include<cstdio>
using namespace std;
int main()
{
    int ans,a,b,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            ans+=a*b;
        }
        printf("%d\n",ans);
    }
    return 0;
}