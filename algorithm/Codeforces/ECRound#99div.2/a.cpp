#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char tmp[120];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",tmp);
        printf("%d\n",strlen(tmp));
    }
    return 0;
}