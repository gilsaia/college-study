#include<cstdio>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        char tmp[1020];
        for(int i=0;i<n;++i){
            switch(i%3){
                case 0:
                    tmp[i]='a';
                    break;
                case 1:
                    tmp[i]='b';
                    break;
                case 2:
                    tmp[i]='c';
                    break;
            }
        }
        tmp[n]='\0';
        printf("%s\n",tmp);
    }
    return 0;
}