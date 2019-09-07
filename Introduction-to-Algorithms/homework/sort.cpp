#include<cstdio>
#include<algorithm>
using namespace std;
int speies[1020];
int main()
{
    int n,L;
    scanf("%d%d",&n,&L);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&speies[i]);
    }
    sort(speies,speies+n);
    int ans=0,sum=0;
    for(int i=0;i<n;++i)
    {
        if((sum+speies[i])<=L)
        {
            ans++;
            sum+=speies[i];
        }
        else
        {
            break;
        }
        
    }
    printf("%d\n",ans);
    return 0;
}