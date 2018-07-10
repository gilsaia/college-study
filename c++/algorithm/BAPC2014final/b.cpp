//题意理解错误，一开始当做dp来做了，实际一个暴力搜索就可以，每次走一步后考虑所有的可能走法然后记录最小步数即可
#include<stdio.h>
#include<queue>
#include<string.h>
#define INF 0x3f3f3f3f
using namespace std;
int step[4000];
int a[20];
int main()
{
    int t,n,m,v,nt,i;
    scanf("%d",&t);
    while(t--)
    {
        memset(step,INF,sizeof(step));
        queue<int>q;
        scanf("%d%d",&n,&m);
        for( i=0 ; i<n ;i++)
            scanf("%d",&a[i]);
        q.push(0);
        step[0]=0;///记录步数
        while(!q.empty())
        {
             v=q.front();
            q.pop();
            for( i=0 ; i<n ;i++)
            {
                nt=v+a[i];///时间点
                if(nt<0)
                    nt=0;
                if(nt>3600)
                    nt=3600;
                if(step[nt]<=step[v]+1)
                    continue;
                 step[nt]=step[v]+1;
                 q.push(nt);
            }
        }
        for( i=m; i<=3600;i++)
            if(step[i]!=INF)
            break;
        printf("%d %d\n",step[i],i-m);
    }
}