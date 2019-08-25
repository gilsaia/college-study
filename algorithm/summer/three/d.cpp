#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int save[220][12][22];
int main()
{
    int L,W;
    scanf("%d%d",&L,&W);
    for(int i=1;i<=L;++i)
    {
        int O,I,S;
        scanf("%d%d%d",&O,&I,&S);
        while((O-I)>=0)
        {
            O-=I;
        }
        for(int j=O;j<W;j+=I)
        {
            save[0][i][j]=1;
        }
        for(int j=0;j<200;++j)
        {
            for(int t=0;t<W;++t)
            {
                if(save[j][i][t]==1)
                {
                    for(int m=1;m<S;++m)
                    {
                        save[j+1][i][(t+m)%W]=2;
                    }
                    save[j+1][i][(t+S)%W]=1;
                }
            }
        }
    }
    int pos;
    scanf("%d",&pos);
    int tx=0,ty=pos;
    char ope[220];
    scanf("%s",ope);
    int time=0;
    int squ=0;
    for(int i=0;ope[i]!='\0';++i)
    {
        ++time;
        if(ope[i]=='U')
        {
            ++tx;
            if(save[time][tx][ty]!=0)
            {
                squ=1;
                break;
            }
        }
        else if(ope[i]=='D')
        {
            if(tx>0)
            {
                --tx;
            }
            if(save[time][tx][ty]!=0)
            {
                squ=1;
                break;
            }
        }
        else if(ope[i]=='L')
        {
            if(ty>0)
            {
                --ty;
            }
            if(save[time][tx][ty]!=0)
            {
                squ=1;
                break;
            }
        }
        else if(ope[i]=='R')
        {
            if(ty<(W-1))
            {
                ++ty;
            }
            if(save[time][tx][ty]!=0)
            {
                squ=1;
                break;
            }
        }
    }
    if(squ==1||tx<=L)
    {
        printf("squish\n");
    }
    else
    {
        printf("safe\n");
    }
    return 0;
}