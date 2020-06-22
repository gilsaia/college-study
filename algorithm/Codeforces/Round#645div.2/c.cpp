#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        long long x1,x2,y1,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        long long tmp=(x2-x1)*(y2-y1);
        long long res=tmp+1;
        printf("%lld\n",res);
    }
    return 0;
}