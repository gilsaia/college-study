//矩阵的幂运算题···
#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
int M,a[5]={1,1,5,11};
mat mul(mat &A,mat &B)
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
mat pow(mat A,int n)
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
int main()
{
    int N;
    while(scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0)
        {
            break;
        }
        if(N<4)
        {
            printf("%d\n",a[N]%M);
            continue;
        }
        mat tas(4,vec(4));
        tas[0][0]=1;tas[0][1]=5;tas[0][2]=1;tas[0][3]=-1;
        tas[1][0]=1;tas[1][1]=0;tas[1][2]=0;tas[1][3]=0;
        tas[2][0]=0;tas[2][1]=1;tas[2][2]=0;tas[2][3]=0;
        tas[3][0]=0;tas[3][1]=0;tas[3][2]=1;tas[3][3]=0;
        tas=pow(tas,N-3);
        int ans=0;
        ans=tas[0][0]*a[3]+tas[0][1]*a[2]+tas[0][2]*a[1]+tas[0][3]*a[0];
        ans%=M;
        ans+=M;
        ans%=M;
        printf("%d\n",ans);
    }
    return 0;
}