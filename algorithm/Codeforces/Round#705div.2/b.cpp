#include<cstdio>
#include<algorithm>
using namespace std;
int reflect[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
bool check(int h,int m,int hou,int mini){
    int hou_r=0,mini_r=0;
    int time=2;
    while(time--){
        int tmp=mini%10;
        if(reflect[tmp]<0){
            return false;
        }
        hou_r*=10;
        hou_r+=reflect[tmp];
        mini/=10;
    }
    time=2;
    while(time--){
        int tmp=hou%10;
        if(reflect[tmp]<0){
            return false;
        }
        mini_r*=10;
        mini_r+=reflect[tmp];
        hou/=10;
    }
    return (mini_r<m)&&(hou_r<h);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int h,m;
        scanf("%d%d",&h,&m);
        int hou,mini;
        scanf("%d:%d",&hou,&mini);
        while(!check(h,m,hou,mini)){
            mini++;
            if(mini==m){
                mini=0;
                hou++;
            }
            if(hou==h){
                hou=0;
            }
        }
        printf("%02d:%02d\n",hou,mini);
    }
    return 0;
}