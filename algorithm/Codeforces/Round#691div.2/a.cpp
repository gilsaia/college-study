#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        char card[2][1020];
        scanf("%s%s",card[0],card[1]);
        int r=0,b=0,e=0;
        for(int i=0;i<n;++i){
            if(card[0][i]>card[1][i]){
                r++;
            }else if(card[0][i]<card[1][i]){
                b++;
            }else{
                e++;
            }
        }
        if(r>b){
            printf("RED\n");
        }else if(r<b){
            printf("BLUE\n");
        }else{
            printf("EQUAL\n");
        }
    }
    return 0;
}