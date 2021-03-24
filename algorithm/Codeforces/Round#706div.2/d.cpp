#include<cstdio>
#include<algorithm>
using namespace std;
int dat[100020];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&dat[i]);
    }
    int res=0,res_n=0;
    int cur=0,left=0,right=0;
    while((cur+1)<n){
        left=cur;
        right=cur;
        while(dat[cur]<dat[cur+1]){
            ++cur;
        }
        int tmp=cur;
        while((tmp+1)<n&&dat[tmp]>dat[tmp+1]){
            ++tmp;
        }
        res++;
        right=tmp;
        int dismin=min(right-cur,cur-left);
        int dismax=max(right-cur,cur-left);
        for(int i=dismin;i<=dismax;++i){
            if(i&1){
                res_n++;
                break;
            }
        }
        cur=right;
    }
    printf("%d\n",res-res_n);
    return 0;
}