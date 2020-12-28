#include<cstdio>
#include<cstring>
using namespace std;
char a[1000200],b[1000200];
int cmap[30][2];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",a);
        scanf("%s",b);
        memset(cmap,0,sizeof(cmap));
        for(int i=0;i<n;++i){
            cmap[a[i]-'a'][0]++;
            cmap[b[i]-'a'][1]++;
        }
        bool suc=true;
        for(int i=0;i<28;++i){
            if(cmap[i][0]<cmap[i][1]){
                suc=false;
                break;
            }else if(cmap[i][0]>cmap[i][1]){
                if(!((cmap[i][0]-cmap[i][1])%k)){
                    cmap[i+1][0]+=(cmap[i][0]-cmap[i][1]);
                    cmap[i][0]=cmap[i][1];
                }else{
                    suc=false;
                    break;
                }
            }
        }
        if(suc){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}