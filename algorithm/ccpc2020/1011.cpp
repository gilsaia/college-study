#include<cstdio>
#include<algorithm>
using namespace std;
int A[55][55];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d",&A[i][j]);
            }
        }
        bool res=true;
        int tmp;
        scanf("%d",&tmp);
        if(tmp==0){
            res=false;
        }
        for(int i=0;i<8;++i){
            scanf("%d",&tmp);
            if(tmp){
                res=false;
            }
        }
        if(res){
            for(int i=0;i<n;++i){
                printf("%d",A[i][0]);
                for(int j=1;j<n;++j){
                    printf(" %d",A[i][j]);
                }
                printf("\n");
            }
        }else{
            for(int i=0;i<n;++i){
                printf("0");
                for(int j=1;j<n;++j){
                    printf(" 0");
                }
                printf("\n");
            }
        }
    }
    return 0;
}