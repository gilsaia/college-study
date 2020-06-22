#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    char dat[1020];
    int num[1020][2];
    while(T--){
        scanf("%s",dat);
        int n=strlen(dat);
        if(n<3){
            printf("0\n");
            continue;
        }
        num[0][0]=0,num[0][1]=0;
        for(int i=0;i<n;++i){
            if(dat[i]=='0'){
                num[i+1][0]=num[i][0]+1;
                num[i+1][1]=num[i][1];
            }else{
                num[i+1][0]=num[i][0];
                num[i+1][1]=num[i][1]+1;
            }
        }
        int ans=1040;
        for(int i=0;i<=n;++i){
            ans=min(ans,num[i][1]+num[n][0]-num[i][0]);
            ans=min(ans,num[i][0]+num[n][1]-num[i][1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}