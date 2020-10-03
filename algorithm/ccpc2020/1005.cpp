#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int num=0,tmp,facnum=0;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            if(tmp!=1){
                num++;
                while(!(tmp%2)){
                    tmp/=2;
                    facnum++;
                }
            }
        }
        if(n==1&&num==0){
            printf("L\n");
        }else if(num==1){
            printf("W\n");
        }else if((num%2)^(facnum%2)){
            printf("L\n");
        }else{
            printf("W\n");
        }
    }
    return 0;
}