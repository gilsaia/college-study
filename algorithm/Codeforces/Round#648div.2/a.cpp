#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int row[52],col[52];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int tmp=0;
                scanf("%d",&tmp);
                if(tmp){
                    row[i]=1,col[j]=1;
                }
            }
        }
        int ans=502,cnt=0;
        for(int i=0;i<n;++i){
            if(!row[i]){
                ++cnt;
            }
        }
        ans=min(ans,cnt);
        cnt=0;
        for(int i=0;i<m;++i){
            if(!col[i]){
                ++cnt;
            }
        }
        ans=min(ans,cnt);
        if(ans%2){
            printf("Ashish\n");
        }else{
            printf("Vivek\n");
        }
    }
    return 0;
}