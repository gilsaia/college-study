//弹性碰撞的题目，实际可以将碰撞理解成相互交错而过即可，但要注意开始是要认为每个球从同一高度出发，最后排完序后加上相应的高度即可
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
const double g=10.0;
int N,H,R,T;
double y[120];
double calc(int T)
{
    if(T<0)
    {
        return H;
    }
    double t=sqrt(2*H/g);
    int k=(int)(T/t);
    if(k%2==0)
    {
        double d=T-k*t;
        return H-g*d*d/2;
    }
    else
    {
        double d=k*t+t-T;
        return H-g*d*d/2;
    }
}
void solve()
{
    for(int i=0;i<N;i++)
    {
        y[i]=calc(T-i);
    }
    sort(y,y+N);
    for(int i=0;i<N;i++)
    {
        printf("%.2f%c",y[i]+2*i*R/100.0,i+1==N?'\n':' ');
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&N,&H,&R,&T);
        solve();
    }
    return 0;
}