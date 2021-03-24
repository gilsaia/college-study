#include<cstdio>
#include<algorithm>
using namespace std;
int dat[100020];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k,datm=0;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i){
            scanf("%d",&dat[i]);
            datm=max(datm,dat[i]);
        }
        sort(dat,dat+n);
        int mex=0;
        while(mex==dat[mex]&&mex<n){
            ++mex;
        }
        int res=0;
        if(mex==n){
            res=n+k;
        }else{
            int tofind=(mex+datm+1)/2;
            bool has=binary_search(dat,dat+n,tofind);
            if(has||!k){
                res=n;
            }else{
                res=n+1;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}