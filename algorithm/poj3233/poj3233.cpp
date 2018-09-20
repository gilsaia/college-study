//一样是矩阵的幂···这种题的难点在于怎么能看出题能够用这种方式做并且找到正确的矩阵
#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
int M;
mat mul(mat &A,mat &B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++)
    {
        for(int k=0;k<B.size();k++)
        {
            for(int j=0;j<B[0].size();j++)
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
    for(int i=0;i<A.size();i++)
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
int n,k;
mat A;
int main()
{
    scanf("%d%d%d",&n,&k,&M);
    for(int i=0;i<n;i++)
    {
        vec tm;
        for(int i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            tm.push_back(tmp);
        }
        A.push_back(tm);
    }
    mat B(n*2,vec(n*2));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            B[i][j]=A[i][j];
        }
        B[n+i][i]=B[n+i][n+i]=1;
    }
    B=pow(B,k+1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a=B[n+i][j]%M;
            if(i==j)
            {
                a=(a+M-1)%M;
            }
            printf("%d%c",a,j+1==n?'\n':' ');
        }
    }
    return 0;
}