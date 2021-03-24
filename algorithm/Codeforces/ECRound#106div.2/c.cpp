#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long res[100020];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        long long n;
        scanf("%lld",&n);
        memset(res,0,sizeof(res));
        long long x,y;
        scanf("%lld%lld",&x,&y);
        long long xres=x*n,yres=y*n;
        res[1]=xres+yres;
        for(int i=2;i<n;++i){
            long long tmp;
            scanf("%lld",&tmp);
            if(i%2){
                if(tmp>y){
                    yres=(yres-y+tmp);
                }
            }
        }
    }
}