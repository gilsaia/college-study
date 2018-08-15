//最大化最小值的练习题，转换一下思路其实和书上的例题一个解法···但是还是有各自扯淡的细节问题···一个是上限1e9卡的话似乎会出问题，还有一个自己写的判断函数总是WA···只能写成书上的样例形式的函数··不知道哪出的问题···
#include<stdio.h>
#include<algorithm>
using namespace std;
int L,N,M,T;
int x[50020];
const int INF=1e9+2;
bool C(int d)
{
    int last=0;
    for(int i=1;i<N-M;i++)
    {
        int crt=last+1;
        while(crt<N&&x[crt]-x[last]<d)
        {
            crt++;
        }
        if(crt==N)
        {
            return false;
        }
        last=crt;
    }
    return true;
}
int main()
{
    scanf("%d%d%d",&L,&N,&M);
    T=N;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&x[i]);
    }
    x[N+1]=L;
    N+=2;
    sort(x,x+N);
    int lb=0,ub=INF;
    while(ub-lb>1)
    {
        int mid=(lb+ub)/2;
        if(C(mid))
        {
            lb=mid;
        }
        else
        {
            ub=mid;
        }
    }
    printf("%d\n",lb);
    return 0;
}