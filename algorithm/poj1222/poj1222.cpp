//还是开关问题···自己照着差不多的那题写的···poj··貌似测评机··又炸了···回来看看对不对吧···
#include<stdio.h>
int ans[8][8],tmp[8][8],put[8][8];
int main()
{
    int t;
    scanf("%d",&t);
    for(int m=1;m<=t;m++)
    {
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=6;j++)
            {
                scanf("%d",&put[i][j]);
            }
        }
        int mines=1e8;
        for(int i=0;i<(1<<6);i++)
        {
            int cnt=0;
            for(int j=0;j<6;j++)
            {
                if((i>>j)&1)
                {
                    tmp[1][j+1]=1;
                    cnt++;
                }
                else
                {
                    tmp[1][j+1]=0;
                }
            }
            for(int j=2;j<=5;j++)
            {
                for(int k=1;k<=6;k++)
                {
                    if((put[j-1][k]+tmp[j-1][k]+tmp[j-1][k-1]+tmp[j-2][k]+tmp[j-1][k+1])%2)
                    {
                        tmp[j][k]=1;
                        cnt++;
                        if(cnt>mines)
                        {
                            goto next1;
                        }
                    }
                    else
                    {
                        tmp[j][k]=0;
                    }
                }
            }
            bool ok;
            ok=1;
            for(int j=1;j<=6;j++)
            {
                if((put[5][j]+tmp[5][j]+tmp[5][j-1]+tmp[5][j+1]+tmp[4][j])%2)
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                mines=cnt;
                for(int j=0;j<=5;j++)
                {
                    for(int k=0;k<=6;k++)
                    {
                        ans[j][k]=tmp[j][k];
                    }
                }
            }
            next1:;
        }
        printf("PUZZLE #%d\n",m);
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=6;j++)
            {
                printf("%d ",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}