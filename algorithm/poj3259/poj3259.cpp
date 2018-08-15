//求负圈的问题，按照模板一套即可，注意双向边和单向边的区别及正负问题
#include<stdio.h>
struct edge
{
    int from,to,cost;
};
edge es[5400];
int d[520];
int main()
{
    int F;
    scanf("%d",&F);
    while(F--)
    {
        int N,M,W;
        scanf("%d%d%d",&N,&M,&W);
        int num=0;
        for(int i=0;i<M;i++)
        {
            int f,t,tim;
            scanf("%d%d%d",&f,&t,&tim);
            es[num].from=f;
            es[num].to=t;
            es[num].cost=tim;
            num++;
            es[num].from=t;
            es[num].to=f;
            es[num].cost=tim;
            num++;
        }
        for(int i=0;i<W;i++)
        {
            int f,t,tim;
            scanf("%d%d%d",&f,&t,&tim);
            es[num].from=f;
            es[num].to=t;
            es[num].cost=-tim;
            num++;
        }
        for(int i=0;i<=N;i++)
        {
            d[i]=0;
        }
        bool pan=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<num;j++)
            {
                edge e=es[j];
                if(d[e.to]>d[e.from]+e.cost)
                {
                    d[e.to]=d[e.from]+e.cost;
                    if(i==N-1)
                    {
                        pan=1;
                        break;
                    }
                }
            }
        }
        if(pan==0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}