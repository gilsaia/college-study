//依旧是二分法的模板题···然而这个思路还是很难想·······
#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF=1e9;
int N,M;
int x[100010];
bool C(int d)
{
    int last=0;
    for(int i=1;i<M;i++)
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
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&x[i]);
    }
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