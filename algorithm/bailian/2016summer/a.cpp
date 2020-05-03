#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int third=1,second=0;
    while(n--){
        int thirdold=third,secondold=second;
        third=thirdold+secondold;
        second=thirdold*2+secondold;
    }
    printf("%d\n",third+second);
    return 0;
}