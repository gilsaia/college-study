#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,s;
    scanf("%d%d",&n,&s);
    if(n*2>s){
        printf("NO\n");
    }else{
        printf("YES\n");
        for(int i=1;i<n;++i){
            printf("2 ");
        }
        printf("%d\n1\n",s-(n-1)*2);
    }
    return 0;
}