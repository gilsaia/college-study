#include<cstdio>
#include<algorithm>
using namespace std;
int maxdig,mindig;
void finddig(long long res){
    maxdig=0,mindig=9;
    while(res){
        int tmp=res%10;
        maxdig=max(maxdig,tmp);
        mindig=min(mindig,tmp);
        if(mindig==0){
            return;
        }
        res/=10;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        long long a,k;
        scanf("%lld%lld",&a,&k);
        for(long long i=1;i<k;++i){
            finddig(a);
            if(mindig==0){
                break;
            }
            a+=(maxdig*mindig);
        }
        printf("%lld\n",a);
    }
    return 0;
}