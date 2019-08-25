#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll bit[2][MAXN];
ll number[MAXN];
ll sum(int i,int siz)
{
    ll s=0;
    while(i>0)
    {
        s^=bit[siz][i];
        i-=i&-i;
    }
    return s;
}
void add(int i,ll x,int siz)
{
    while(i<=MAXN)
    {
        bit[siz][i]^=x;
        i+=i&-i;
    }
}
void init(int n)
{
    for(int i=0;i<=n+2;++i)
    {
        bit[0][i]=bit[1][i]=0;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int c=1;c<=T;++c)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        init(n);
        for(int i=1;i<=n;++i)
        {
            ll tmp;
            scanf("%lld",&tmp);
            add(i/2+1,tmp,i%2);
            number[i]=tmp;
        }
        printf("Case #%d:\n",c);
        for(int i=0;i<m;++i)
        {
            int ope,x,y;
            scanf("%d%d%d",&ope,&x,&y);
            if(ope==0)
            {
                add(x/2+1,number[x],x%2);
                add(x/2+1,y,x%2);
                number[x]=y;
            }
            else
            {
                if((y-x+1)%2)
                {
                    ll res=sum(y/2+1,y%2);
                    if((x/2)!=0)
                    {
                        res^=sum(x/2,x%2);
                    }
                    printf("%lld\n",res);
                }
                else
                {
                    printf("0\n");
                }
            }
        }
    }
    return 0;
}