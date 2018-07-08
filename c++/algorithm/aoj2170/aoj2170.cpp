//并查集的简单应用，但是题意研究了好长时间···
//实际上一开始给了个树，输入的数据是第n个节点对应的父亲是哪个节点，这里直接用一个数组保存即可，注意不要状态压缩，因为后面有标记的存在
//给的两种操作Q指第n个节点的根节点是第n个，M指是对应的n节点称为根节点，即单独称为一个新的树，并查集中只要将上一层改成根即可
//注意不能状态压缩，不然后面分开树时会有问题
#include<stdio.h>
int par[100010];
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
int main()
{
    int N,Q;
    while(scanf("%d%d",&N,&Q))
    {
        if(N==0&&Q==0)
        {
            break;
        }
        par[1]=1;
        for(int i=2;i<=N;i++)
        {
            scanf("%d",&par[i]);
        }
        char k;
        int temp;
        long long ans=0;
        for(int i=0;i<Q;i++)
        {
            scanf("\n%c%d",&k,&temp);
            if(k=='Q')
            {
                ans+=find(temp);
            }
            else
            {
                par[temp]=temp;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}