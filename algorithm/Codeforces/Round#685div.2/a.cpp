#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int tmp;
        scanf("%d",&tmp);
        if(tmp==1){
            printf("0\n");
        }else if(tmp==2){
            printf("1\n");
        }else if(tmp==3){
            printf("2\n");
        }else if(tmp%2){
            printf("3\n");
        }else{
            printf("2\n");
        }
    }
    return 0;
}