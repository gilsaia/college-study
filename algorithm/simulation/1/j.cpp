#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;

ll MOD=123456789;
void mult(ll A[6][6],ll B[6][6])
{
    ll C[6][6];
    for(int i=0;i<6;++i)
    {
        for(int j=0;j<6;++j)
        {
            C[i][j]=0;
        }
    }
    for(int i=0;i<6;++i)
    {
        for(int j=0;j<6;++j)
        {
            for(int k=0;k<6;++k)
            {
                C[i][j]+=A[i][k]*B[k][j];
                C[i][j]%=MOD;
            }
        }
    }
    for(int i=0;i<6;++i)
    {
        for(int j=0;j<6;++j)
        {
            A[i][j]=C[i][j];
        }
    }
}
void mat_pow(ll A[6][6],ll b)
{
    ll res[6][6];
    for(int i=0;i<6;++i)
    {
        for(int j=0;j<6;++j)
        {
            res[i][j]=0;
        }
    }
    for(int i=0;i<6;++i)
    {
        res[i][i]=1;
    }
    while(b)
    {
        if(b&1)
        {
            mult(res,A);
        }
        b>>=1;
        mult(A,A);
    }
    for(int i=0;i<6;++i)
    {
        for(int j=0;j<6;++j)
        {
            A[i][j]=res[i][j];
        }
    }
}

ll solve(ll n)
{
    if(n<3)
    {
        return n;
    }
    ll A[6][6];
    for(int i=0;i<6;++i)
    {
        for(int j=0;j<6;++j)
        {
            A[i][j]=0;
        }
    }
    A[0][0]=1,A[0][1]=2,A[0][2]=1,A[1][0]=1,A[2][2]=1,A[2][3]=3,A[2][4]=3,A[2][5]=1;
    A[3][3]=1,A[3][4]=2,A[3][5]=1,A[4][4]=1,A[4][5]=1,A[5][5]=1;
    mat_pow(A,n-2);
    ll res=0;
    ll mul[6]={2,1,27,9,3,1};
    for(int i=0;i<6;++i)
    {
        res+=A[0][i]*mul[i];
        res%=MOD;
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        ll tmp;
        scanf("%lld",&tmp);
        tmp=solve(tmp);
        printf("%lld\n",tmp);
    }
    return 0;
}