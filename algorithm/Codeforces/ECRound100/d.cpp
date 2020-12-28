#include<cstdio>
#include<algorithm>
using namespace std;
int sein[200020];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&sein[i]);
        }
        int minn=0,maxn=n;
        int pos=0;
        while(pos<n&&sein[pos]==(pos+1)){
            ++pos;
        }
        if(pos){
            minn=max(minn,pos);
        }else{
            maxn=min(maxn,sein[0]-1);
        }
        pos=n-1;
        int posvalue=n*2;
        while(pos>=0&&sein[pos]==posvalue){
            --pos,--posvalue;
        }
        if(pos==(n-1)){
            minn=max(minn,n*2-sein[n-1]);
        }else{
            maxn=min(maxn,pos+1);
        }
        printf("%d\n",maxn-minn+1);
    }
    return 0;
}