//并查集问题，但是对于如何判断那些电脑能够相互连接写的只是暴力搜索仍可优化
#include<stdio.h>
#include<iostream>
struct position
{
    int x,y;
};
position dat[1020];
int par[1400],used[1020];
int d;
int find(int x)
{
    if(par[x]==x)
    {
        return x;
    }
    else
    {
        return find(par[x]);
    }
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
    {
        return;
    }
    else
    {
        par[x]=y;
        return;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
bool cmp(position a,position b)
{
    int t=a.x-b.x,m=a.y-b.y;
    t*=t,m*=m;
    int temp=t+m;
    if(temp<=d*d)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int N;
    scanf("%d%d",&N,&d);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&dat[i].x,&dat[i].y);
    }
    char k;
    int num=0;
    while(std::cin>>k)
    {
        if(k=='O')
        {
            int i;
            scanf("%d",&i);
            par[i]=i;
            for(int m=1;m<=num;m++)
            {
                if(cmp(dat[i],dat[used[m]]))
                {
                    unite(i,used[m]);
                }
            }
            num++;
            used[num]=i;
        }
        else
        {
            int i,m;
            scanf("%d%d",&i,&m);
            if(par[i]!=0&&par[m]!=0)
            {
                if(same(i,m))
                {
                    printf("SUCCESS\n");
                }
                else
                {
                    printf("FAIL\n");
                }
            }
            else
            {
                printf("FAIL\n");
            }
        }
    }
    return 0;
}