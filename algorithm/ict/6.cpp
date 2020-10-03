#include<cstdio>
using namespace std;
// 数学小天才思路 考虑到所给参数值并不大 直接暴力求解 对于重根的情况再考虑如何判断 复杂度O(4000)
int main(){
    int a[4];
    for(int i=0;i<4;++i){
        scanf("%d",&a[i]);
    }
    double x=-20;
    bool pos=(a[0]+a[1]*x+a[2]*x*x+a[3]*x*x*x)>0;
    bool oldpos=pos;
    int num=0;
    while(x<20){
        double res=a[0]+a[1]*x+a[2]*x*x+a[3]*x*x*x;
        bool newpos=res>0;
        if((pos^newpos)&&(newpos^oldpos)){
            if(num){
                printf(" ");
            }
            printf("%.2lf",x);
            ++num;
        }
        oldpos=pos;
        pos=newpos;
        x+=0.01;
    }
    if(!num){
        printf("None");
    }
    printf("\n");
    return 0;
}