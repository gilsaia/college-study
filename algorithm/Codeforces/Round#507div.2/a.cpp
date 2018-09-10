#include<stdio.h>
int pos[50];
int main()
{
    int n,a,b,min,ans=0;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pos[i]);
    }
    if(a<b)
    {
        min=a;
    }
    else
    {
        min=b;
    }
    for(int i=0;i<n/2;i++)
    {
        int tobuy=0,white=0,black=0;
        if(pos[i]==0)
        {
            white++;
        }
        else if(pos[i]==1)
        {
            black++;
        }
        else 
        {
            tobuy++;
        }
        if(pos[n-i-1]==0)
        {
            white++;
        }
        else if(pos[n-i-1]==1)
        {
            black++;
        }
        else
        {
            tobuy++;
        }
        if(white&black)
        {
            printf("-1\n");
            return 0;
        }
        if(tobuy==2)
        {
            ans+=2*min;
            continue;
        }
        if(tobuy==0)
        {
            continue;
        }
        else
        {
            if(white)
            {
                ans+=a;
            }
            else
            {
                ans+=b;
            }
        }
    }
    if((n&1)&&pos[n/2]==2)
    {
        ans+=min;
    }
    printf("%d\n",ans);
    return 0;
}