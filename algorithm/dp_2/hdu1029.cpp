#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(~scanf("%d",&n)){
        int count=0,number=0;
        for(int i=0;i<n;++i){
            int tmp;
            scanf("%d",&tmp);
            if(number!=tmp){
                if(count<=1){
                    number=tmp;
                }else{
                    --count;
                }
            }else{
                ++count;
            }
        }
        printf("%d\n",number);
    }
    return 0;
}