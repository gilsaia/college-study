#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int tim[101010];
int request[100010];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&request[i]);
        for(int t=0;t<1000;t++)
        {
            tim[request[i]+t]++;
        }
    }
    int ans=0;
    for(int i=0;i<=100000;i++)
    {
        int temp=(tim[i]%k==0)?0:1;
        ans=max(ans,tim[i]/k+temp);
    }
    printf("%d\n",ans);
    return 0;
}