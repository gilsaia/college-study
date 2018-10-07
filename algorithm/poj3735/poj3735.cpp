//矩阵快速幂的问题····自己写的思路一样为啥···tle？？？
#include <cstdio>
#include <cstring>
#define ll long long
struct matrix
{
    ll m[105][105];
}a;
 
int n, k;
ll m;
 
matrix multiply(matrix x, matrix y)    
{    
    matrix ans;    
    memset(ans.m, 0, sizeof(ans.m));    
    for(int i = 1; i <= n; i++)    
        for(int j = 1; j <= n; j++)    
            if(x.m[i][j])    
                for(int k = 1; k <= n; k++)    
                    ans.m[i][k] = (ans.m[i][k] + x.m[i][j] * y.m[j][k]);    
    return ans;    
}  
 
matrix quickmod(int p)    
{    
    matrix ans;    
    memset(ans.m, 0, sizeof(ans.m));    
    for(int i = 1; i <= n; i++)    
        ans.m[i][i] = 1;    
    while(p)    
    {    
        if(p & 1)    
            ans = multiply(ans, a);    
        p >>= 1;    
        a = multiply(a, a);    
    }    
    return ans;    
}  
 
int main()
{
    while(scanf("%d %lld %d", &n, &m, &k) != EOF && (n + m + k))
    {
        n++;
        char s[10];
        int x, y;
        memset(a.m, 0, sizeof(a.m));
        for(int i = 1; i <= n; i++)
            a.m[i][i] = 1;
        for(int i = 0; i < k; i++)
        {
            scanf("%s", s);
            if(s[0] == 'g')
            {
                scanf("%d", &x);
                a.m[x][n]++;
            }
            if(s[0] == 'e')
            {
                scanf("%d", &x);
                for(int j = 1; j <= n; j++)
                    a.m[x][j] = 0;
            }
            if(s[0] == 's')
            {
                scanf("%d %d", &x, &y);
                for(int j = 1; j <= n; j++)
                {
                    ll tmp = a.m[x][j];
                    a.m[x][j] = a.m[y][j];
                    a.m[y][j] = tmp;
                }
            }
        }
        matrix ans = quickmod(m);
        for(int i = 1; i < n; i++)
            printf("%lld ", ans.m[i][n]);
        printf("\n");
    }
} 

/*#include<cstdio>
//#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<long long> vec;
typedef vector<vec> mat;
typedef long long ll;
mat mul(mat &A,mat &B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();++i)
    {
        for(int k=0;k<B.size();++k)
        {
            for(int j=0;j<B[0].size();++j)
            {
                C[i][j]=(C[i][j]+A[i][k]*B[k][j]);
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
    int n,k;
    long long m;
    while(scanf("%d%lld%d",&n,&m,&k))
    {
        if(n==0&&m==0&&k==0)
        {
            break;
        }
        mat ans(n+1,vec(n+1,0));
        for(int i=0;i<=n;i++)
        {
            ans[i][i]=1;
        }
        for(int i=0;i<k;i++)
        {
            char c[10];
            scanf("%s",&c);
            switch(c[0])
            {
                case 'g':
                int tmp;
                scanf("%d",&tmp);
                --tmp;
                ++ans[tmp][n];
                break;
                case 'e':
                int tmpe;
                scanf("%d",&tmpe);
                --tmpe;
                for(int i=0;i<=n;++i)
                {
                    ans[tmpe][i]=0;
                }
                break;
                case 's':
                int t1,t2;
                scanf("%d%d",&t1,&t2);
                --t1,--t2;
                for(int i=0;i<=n;i++)
                {
                    int chan=ans[t1][i];
                    ans[t1][i]=ans[t2][i];
                    ans[t2][i]=chan;
                }
                swap(ans[t1],ans[t2]);
                break;
                default:
                break;
            }
        }
        ans=pow(ans,m);
        printf("%lld",ans[0][n]);
        for(int i=1;i<n;++i)
        {
            printf(" %lld",ans[i][n]);
        }
        printf("\n");
    }
    return 0;
}*/