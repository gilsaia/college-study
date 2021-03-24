#include<cstdio>
#include<algorithm>
using namespace std;
int dat[520];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,x;
        scanf("%d%d",&n,&x);
        for(int i=0;i<n;++i){
            scanf("%d",&dat[i]);
        }
        int pos=1,res=0;
        bool can=true;
        while(pos<n){
            if(dat[pos-1]>dat[pos]){
                if(x>dat[pos]){
                    can=false;
                    break;
                }
                int offset=upper_bound(dat,dat+pos-1,x)-dat;
                while(offset<pos){
                    if(dat[offset]>x){
                        swap(dat[offset],x);
                        ++res;
                    }
                    ++offset;
                }
            }
            ++pos;
        }
        if(can){
            printf("%d\n",res);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}