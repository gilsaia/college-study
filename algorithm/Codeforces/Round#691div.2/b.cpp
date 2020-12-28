#include<cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int num[2]={1,1};
    for(int i=1;i<=n;++i){
        int edge=(1+(i+1)/2*2);
        if(i%2){
            num[1]=edge*edge/2;
        }else{
            num[0]=edge*edge-num[0]-num[1];
        }
    }
    printf("%d\n",num[n%2]);
    return 0;
}