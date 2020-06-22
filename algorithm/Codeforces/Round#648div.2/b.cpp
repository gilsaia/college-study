#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int tmp,lasttmp=0,disorder=0;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            if(tmp>=lasttmp){
                lasttmp=tmp;
            }else{
                disorder=1;
            }
        }
        int has[2]={0,0};
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            if(tmp){
                has[1]=1;
            }else{
                has[0]=1;
            }
        }
        if(has[0]^has[1]&&disorder){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
    return 0;
}