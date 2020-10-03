#include<cstdio>
#include<algorithm>
using namespace std;
const long long MAXN=0x3f3f3f3f;
int main(){
    int T;
    scanf("%d",&T);
    long long n,m,k;
    while(T--){
        long long res=0;
        scanf("%lld%lld%lld",&n,&m,&k);
        res+=(k-1)*2;
        long long minres=MAXN;
        for(int i=0;i<m;++i){
            long long tmp;
            scanf("%lld",&tmp);
            minres=min(minres,tmp);
            res+=abs(k-tmp)*2;
        }
        if(minres<k){
            res-=abs(k-minres)*2;
        }
        printf("%lld\n",res);
    }
    return 0;
}