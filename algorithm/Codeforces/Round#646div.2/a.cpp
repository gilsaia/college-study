#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,x;
        scanf("%d%d",&n,&x);
        int odd=0,even=0,tmp;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            if(tmp&1){
                ++odd;
            }else{
                ++even;
            }
        }
        bool can=1;
        if(odd==0){
            can=0;
        }else{
            int oddpair=(odd-1)/2*2;
            int need=(x-1)/2*2;
            int actual=min(need,oddpair);
            if((x-1-actual)>even){
                can=0;
            }
        }
        if(can){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}