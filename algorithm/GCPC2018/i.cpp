//今天实在忙没时间写了···这题似乎是没理解对题意反正很奇怪··
#include<stdio.h>
int hero[1010],vili[1010];
bool win(int n)
{
    int temp1=0,temp2=0;
    for(int i=n-1;i>0;i--)
    {
        int heros=hero[i]+temp1;
        int vilis=vili[i]+temp2;
        if(heros>vilis)
        {
            temp1+=hero[i];
            temp2=0;
        }
        else if(heros<vilis)
        {
            temp1=0;
            temp2+=vili[i];
        }
        else
        {
            temp1+=hero[i];
            temp2=0;
        }
    }
    return (temp1+hero[0])>(temp2+vili[0]);
}
void increa(int n)
{
    for(int i=0;i<n;i++)
    {
        hero[i]++;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&hero[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&vili[i]);
    }
    int ans=0;
    while(!win(n))
    {
        increa(n);
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}