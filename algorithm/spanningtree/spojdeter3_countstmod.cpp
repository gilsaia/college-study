#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
long long a[205][205];
 
long long solved(long long N,long long MOD)
{
    int sign = 0;
    long long ans=1;
    for(int i=0;i<N;i++)//当前行
    {
        for(int j=i+1;j<N;j++)//当前之后的每一行，因为每一行的当前第一个数要转化成0（想想线性代数中行列式的计算）
        {
            int x=i,y=j;
            while(a[y][i])//利用gcd的方法，不停地进行辗转相除
            {
                long long t=a[x][i]/a[y][i];
 
                for(int k=i;k<N;k++)
                    a[x][k]=(a[x][k]-a[y][k]*t)%MOD;
 
                swap(x,y);
            }
            if(x!=i)//奇数次交换，则D=-D'整行交换
            {
                for(int k=0;k<N;k++)
                    swap(a[i][k],a[x][k]);
                sign ^= 1;
            }
        }
        if(a[i][i]==0)//斜对角中有一个0，则结果为0
        {
            return 0;
        }
 
        else
            ans=ans*a[i][i]%MOD;
 
    } 
    if(sign!=0)ans *= -1;
    if(ans<0)ans += MOD;
    return ans;
}
int main()
{
    ll n,p;
    while(~scanf("%lld%lld",&n,&p))
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%lld",&a[i][j]);
            }
        }
        ll ans=solved(n,p);
        printf("%lld\n",ans);
    }
    return 0;
}