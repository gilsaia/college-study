#include<vector>
#include<cstdio>
using namespace std;
typedef vector<long long> vec;
typedef vector<vec> mat;
typedef long long ll;
const int M=1e9+7;
mat mul(mat &A,mat&B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();++i)
    {
        for(int k=0;k<B.size();++k)
        {
            for(int j=0;j<B[0].size();++j)
            {
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;
            }
        }
    }
    return C;
}
mat pow(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<A.size();++i)
    {
        B[i][i]=1;
    }
    while(n>0)
    {
        if(n&1)
        {
            B=mul(B,A);
        }
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
void solve(ll n)
{
    mat A(2,vec(2));
    A[0][0]=1;A[0][1]=1;
    A[1][0]=1;A[1][1]=0;
    A=pow(A,n);
    printf("%lld\n",A[1][0]);
}
int main()
{
    int K;
    scanf("%d",&K);
    for(int i=0;i<K;++i)
    {
        ll tmp;
        scanf("%lld",&tmp);
        solve(tmp);
    }
    return 0;
}