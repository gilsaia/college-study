#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll a[200020],res[200020];
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    if(n>2){
        a[1]=gcd(a[1]-a[0],a[2]-a[0]);
    }else if(n==2){
        a[1]-=a[0];
    }
    for(int i=3;i<n;++i){
        a[1]=gcd(a[1],a[i]-a[0]);
    }
    for(int i=0;i<m;++i){
        ll b;
        scanf("%lld",&b);
        if(n==1){
            res[i]=a[0]+b;
        }else{
            res[i]=gcd(a[0]+b,a[1]);
        }
    }
    printf("%lld",res[0]);
    for(int i=1;i<m;++i){
        printf(" %lld",res[i]);
    }
    printf("\n");
    return 0;
}