#include <cstdio>  
#include <cstring>  
#include<algorithm>
#define maxn 50047  
using namespace std;
int c[maxn]; 
int n;
int Lowbit(int x)  // 2^k
{
	return x&(-x);
}
void update(int i, int x)//i点增量为x
{
	while(i <= n)
	{
		c[i] += x;
		i += Lowbit(i);
	}
}
int sum(int x)//区间求和 [1,x]
{
	int sum=0;
	while(x>0)
	{
		sum+=c[x];
		x-=Lowbit(x);
	}
	return sum;
}
  
int Getsum(int x1,int x2) //求任意区间和
{ 
    return sum(x2) - sum(x1-1); 
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        printf("Case %d:\n",t);
        scanf("%d",&n);
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;++i)
        {
            int tmp;
            scanf("%d",&tmp);
            update(i,tmp);
        }
        char op[10];
        while(~scanf("%s",op))
        {
            if(op[0]=='E')
            {
                break;
            }
            else if(op[0]=='A')
            {
                int a,b;
                scanf("%d%d",&a,&b);
                update(a,b);
            }
            else if(op[0]=='S')
            {
                int a,b;
                scanf("%d%d",&a,&b);
                b*=-1;
                update(a,b);
            }
            else if(op[0]=='Q')
            {
                int a,b;
                scanf("%d%d",&a,&b);
                int out=Getsum(a,b);
                printf("%d\n",out);
            }
        }
    }
    return 0;
}