#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long month[400020],su[400020];
long long last(int t){
    long long tmpindex;
    while(tmpindex=(upper_bound(su,su+n+1,t)-su),tmpindex!=(n+1)){
        return su[tmpindex]-t;
    }
    return 0;
}
long long val(long long start,long long len){
    long long res=0,las=0,tmpindex;
    while(tmpindex=(upper_bound(su,su+n+1,start)-su),tmpindex!=(n+1)){
        if(len==0){
            break;
        }
        int i=tmpindex;
        long long tmplen=min(len,su[i]-start);
        las=0;
        if(i!=0){
            las=su[i-1];
        }
        long long calst=start-las+1;
        res+=(calst+calst+tmplen-1)*tmplen/2;
        start+=tmplen;
        len-=tmplen;
    }
    // for(int i=0;i<=n;++i){
    //     if(len==0){
    //         break;
    //     }
    //     if(su[i]>start){
    //         long long tmplen=min(len,su[i]-start);
    //         long long calst=start-las+1;
    //         res+=(calst+calst+tmplen-1)*tmplen/2;
    //         start+=tmplen;
    //         len-=tmplen;
    //     }
    //     las=su[i];
    // }
    return res;
}
int main(){
    int x;
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;++i){
        scanf("%lld",&month[i]);
        month[n+i]=month[i];
    }
    n=n*2;
    su[0]=month[0];
    for(int i=0;i<n;++i){
        su[i+1]=su[i]+month[i+1];
    }
    long long ans=val(0,x),start=0,las=x;
    long long res=ans;
    long long tmp=0;
    while(tmp=last(las)){
        ans-=val(start,tmp);
        ans+=val(las,tmp);
        res=max(res,ans);
        start+=tmp;
        las+=tmp;
    }
    printf("%lld\n",res);
    return 0;
}