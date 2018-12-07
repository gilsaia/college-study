#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int save[1020][1020],condition[1020][1020];
int main()
{
    int N,M,dx[8]={0,0,1,-1,1,1,-1,-1},dy[8]={1,-1,0,0,1,-1,1,-1};
    cin>>N>>M;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>condition[i][j];
            if(condition[i][j]==1)
            {
                for(int t=0;t<8;++t)
                {
                    int tx=i+dx[t],ty=j+dy[t];
                    if(tx>=0&&ty>=0&&ty<N&&ty<M)
                    {
                        save[tx][ty]++;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            if(condition[i][j]==1&&(save[i][j]>3||save[i][j]<2))
            {
                --ans;
            }
            if(condition[i][j]==0&&save[i][j]==3)
            {
                ++ans;
            }
        }
    }
    if(ans>0)
    {
        printf("more\n");
    }
    else if(ans<0)
    {
        printf("less\n");
    }
    else
    {
        printf("unchanged\n");
    }
    return 0;
}