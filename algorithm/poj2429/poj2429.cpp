//这道题emmmmmmmm真的真的不会做··思路倒是不很难想，最后要求就是将给定的数拆成两个互质的素数因子且令其和最小···但是数论现在是真的啥也不会···
//判断是否为素数用的miller-rabin法，拆因子用的pollard_rho法···这俩真的是基本没听过的玩意···只能说是学习的算法还不够深啊···
#include<iostream>
#include<ctime>
#include<algorithm>
#include<cmath>
using namespace std;
long long p,f[1000],ans;
long long f2[1000],q;
long long mod2(long long a,long long b,long long n)// a*b%n
{
    long long  exp = a%n, res = 0;
    while(b){
        if(b&1){
            res += exp;
            if(res>n) res -= n;
        }
        exp <<= 1;
        if(exp>n)  exp -= n;
        b>>=1;
    }
    return res;
}
 
long long mod(long long a,long long b,long long m) //(a^b)%n
{
    long long exp=a%m, res=1;
    while(b>=1){
        if(b&1)
            res=mod2(res,exp,m);
        exp = mod2(exp,exp,m);
        b>>=1;
    }
    return res;
}
//miller-rabin法测试素数
bool miller_rabin(long long n)
{
    if(n==2)return 1;
    if(n<2||!(n&1))return 0;
    long long a, u=n-1, x, y;
    int t=0;
    while(u%2==0){
        t++;
        u/=2;
    }
    srand(time(0));
    for(int i=0;i<10;i++) {
        a = rand() % (n-1) + 1;
        x = mod(a, u, n);
        for(int j=0;j<t;j++){
            y = mod2(x, x, n);
            if ( y == 1 && x != 1 && x != n-1 )
                return false;
            x = y;
        }
        if( y!=1) return false;
    }
    return true;
}
// 因子分解
long long gcd(long long a,long long b){
    long long c;
    while(b){
        c=b; b=a%b; a=c;
    }
    return a;
}
long long pollard_rho(long long n,long long k){
    srand(time(0));
    long long x=rand()%(n-1)+1;
    long long i=1,t=2,y=x,d;
    while(1){
        i++;
        x=(mod2(x,x,n)+k)%n;
        d=gcd(y-x,n);
        if(d>1 && d<n) return d;
        if(x==y) return n;
        if(t==i) y=x,t<<=1;
    }
}
void get_factor(long long n,long long k){
    if(miller_rabin(n)){
        f[p++]=n;
       return ;
    }
    long long h=n;
    while(h>=n)
        h=pollard_rho(h,k--);
    get_factor(h,k);
    get_factor(n/h,k);
}
void dfs(long long i,long long x,long long k){
    if(i>q) return ;
    if(x>ans && x<=k) ans=x;
    dfs(i+1,x,k);
    x*=f2[i];
    if(x>ans && x<=k) ans=x;
    dfs(i+1,x,k);
}
int main(int argc, char** argv) {
    long long m,n,k;
    while(scanf("%lld%lld",&m,&n)!=-1){
        if(m==n){
            printf("%lld %lld\n",m,n); continue;
        }
        k=n/m; p=0; q=0; ans=1;
        get_factor(k,180);
        sort(f,f+p);
        f2[0]=f[0];
        for(int i=0;i<p-1;i++)
            if(f[i]==f[i+1]) f2[q]*=f[i+1];
            else{
                q++; f2[q]=f[i+1];
            }
        long long tmp=(long long)sqrt(k*1.0);
        dfs(0,1,tmp);
        printf("%lld %lld\n",m*ans,k/ans*m);
    }
    return 0;
}