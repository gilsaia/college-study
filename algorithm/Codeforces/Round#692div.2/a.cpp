#include<cstdio>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        char tmp[120];
        scanf("%d%s",&n,tmp);
        int len=0;
        for(int i=n-1;i>=0;--i){
            if(tmp[i]==')'){
                len++;
            }else{
                break;
            }
        }
        if(len>(n-len)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}