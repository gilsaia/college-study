#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int prime[1000020];
vector<int> fpri;
void pre(){
    prime[0]=prime[1]=1;
    for(int i=2;i<1000000;++i){
        if(!prime[i]){
            for(int j=i*2;j<1000000;j+=i){
                prime[j]=1;
            }
        }
    }
    for(int i=2;i<1000000;++i){
        if(!prime[i]){
            fpri.push_back(i);
        }
    }
}
int main(){
    int T;
    pre();
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int res=0;
        if(n==1){
            res=1;
        }else if(n==2){
            res=0;
        }else if(n&1){
            res=0;
        }else{
            int tmp=n/2;
            if(tmp%2){
                for(int i=0;i<fpri.size();++i){
                    if(tmp%fpri[i]==0){
                        if(tmp/fpri[i]==1){
                            res=1;
                        }
                        break;
                    }
                }
            }else{
                while(tmp%2==0){
                    tmp/=2;
                }
                if(tmp==1){
                    res=1;
                }
            }
        }
        if(res){
            printf("FastestFinger\n");
        }else{
            printf("Ashishgup\n");
        }
    }
    return 0;
}
