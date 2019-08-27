#include<stdio.h>
const int N = 100005;
int flag[N], father[N];
void Init()
{
    for(int i = 0; i <= 100000; i++)
        flag[i] = 0, father[i] = i;
}
int Find(int x)
{
    if(x != father[x])
        father[x] = Find(father[x]);
    return father[x];
}
void Merge(int a, int b)
{
    int p = Find(a);
    int q = Find(b);
    father[p] = q;
}
int main()
{
    int a, b;
    int num=1;
    while(~scanf("%d%d",&a,&b))
    {
 
        if(a == -1 && b == -1)
            break;
        Init();
        int FLAG = 0;
        while(1)
        {
            if(a == 0 && b == 0)
                break;
            if(Find(a) == Find(b))
                FLAG = 1;
            Merge(a,b);
            flag[a] = 1, flag[b] = 1;
            scanf("%d%d",&a,&b);
        }
        if(FLAG == 1)
            printf("Case %d is not a tree.\n",num++);
        else
        {
            int sum = 0;
            for(int i = 0; i <= 100000; i++)
                if(flag[i] && father[i] == i)
                    sum++;
            //printf("%d\n",sum);
            if(sum > 1)
                printf("Case %d is not a tree.\n",num++);
            else
                printf("Case %d is a tree.\n",num++);
        }
    }
    return 0;
}