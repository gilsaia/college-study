#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll beginpos,endpos,timeend,timebegin,dir,lastpos;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        beginpos=0,endpos=0,timebegin=0,timeend=0,dir=0,lastpos=0;
        int n;
        int res=0;
        scanf("%d",&n);
        ll t,x;
        scanf("%lld%lld",&t,&x);
        beginpos=0;
        endpos=x;
        timeend=t+abs(endpos-beginpos);
        timebegin=t;
        dir=(endpos>beginpos)?1:-1;
        if(endpos==beginpos){
            dir=0;
        }
        lastpos=x;
        for(int i=1;i<n;++i){
            scanf("%lld%lld",&t,&x);
            if(t<timeend){
                
            }else{
                
            }
        }
        printf("%d\n",res);
    }
    return 0;
}