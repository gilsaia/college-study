//二维的树状数组题···之前从没用过二维树状数组···这道题很好的熟悉了···别的没啥要点···看好怎么翻转就好···
#include<cstdio>
#include<iostream>
using namespace std;
int bit[1020][1020],n;
int sum(int x,int y)
{
    int s=0;
    for(int i=x;i>0;i-=i&-i)
    {
        for(int j=y;j>0;j-=j&-j)
        {
            s+=bit[i][j];
        }
    }
    return s;
}
void add(int x,int y,int t)
{
    for(int i=x;i<=n;i+=i&-i)
    {
        for(int j=y;j<=n;j+=j&-j)
        {
            bit[i][j]+=t;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                bit[i][j]=0;
            }
        }
        for(int i=0;i<m;i++)
        {
            char tmp;
            cin>>tmp;
            if(tmp=='C')
            {
                int x1,x2,y1,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                add(x1,y1,1);
                add(x2+1,y1,1);
                add(x1,y2+1,1);
                add(x2+1,y2+1,1);
            }
            else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                int ans=0;
                if(sum(x,y)%2)
                {
                    ans=1;
                }
                printf("%d\n",ans);
            }
        }
        printf("\n");
    }
    return 0;
}