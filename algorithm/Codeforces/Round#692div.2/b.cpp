#include<cstdio>
using namespace std;
#define ll long long
bool cmp(ll n){
    ll tmp=n;
    while(tmp){
        ll dig=tmp%10;
        if(dig&&n%dig){
            return false;
        }
        tmp/=10;
    }
    return true;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll n;
        scanf("%lld",&n);
        for(ll i=n;;++i){
            if(cmp(i)){
                n=i;
                break;
            }
        }
        printf("%lld\n",n);
    }
    return 0;
}