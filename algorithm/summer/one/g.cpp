#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
    int num,cap;
};
bool cmp(node a,node b)
{
    return a.cap>b.cap;
}
int ran[100020];
int diver[3][100020];
node tosor[100020];
int used[100020];
int main()
{
    int N,Q;
    scanf("%d%d",&N,&Q);
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<N;++j)
        {
            tosor[j].num=j;
            scanf("%d",&tosor[j].cap);
        }
        sort(tosor,tosor+N,cmp);
        int nowrank=0,nowcap=-1;
        for(int j=0;j<N;++j)
        {
            if(i==0)
            {
                ran[j]=tosor[j].num;
            }
            if(tosor[j].cap==nowcap)
            {
                diver[i][tosor[j].num]=nowrank;
            }
            else
            {
                nowrank=j;
                nowcap=tosor[j].cap;
                diver[i][tosor[j].num]=nowrank;
            }
        }
    }
    for(int i=0;i<Q;++i)
    {
        int numtmp;
        scanf("%d",&numtmp);
        --numtmp;
        if(used[numtmp]==0)
        {
            int rantmp=diver[0][numtmp];
            for(int j=rantmp-1;j>=0;--j)
            {
                int todef=ran[j];
                if(diver[1][todef]<diver[1][numtmp]&&diver[2][todef]<diver[2][numtmp])
                {
                    used[numtmp]=-1;
                    goto L1;
                }
            }
            used[numtmp]=1;
        }
L1:     if(used[numtmp]==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}