#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    long long a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    long long x=b-a+1,y=c-b+1,z=d-c+1;
    long long minnum=min(x,y),maxnum=max(x,y);
    long long maxval=d;
    long long res=0;
    long long tmpnum=0,tmpval=a+b;
    for(long long i=0;i<maxnum;++i){
        if(tmpnum<minnum){
            ++tmpnum;
        }
        if(tmpval>maxval){
            long long tmp=z*tmpnum;
            res+=tmp;
        }else{
            long long tmp=tmpnum*max(0LL,tmpval-c);
            res+=tmp;
        }
        ++tmpval;
    }
    while(tmpnum){
        --tmpnum;
        if(tmpval>maxval){
            long long tmp=z*tmpnum;
            res+=tmp;
        }else{
            long long tmp=tmpnum*max(0LL,tmpval-c);
            res+=tmp;
        }
        ++tmpval;        
    }
    printf("%lld\n",res);
    return 0;
}