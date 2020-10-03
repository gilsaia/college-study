#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
// 成绩排序思路 利用结构体自定义比较函数即可 整个过程复杂度最高的为调用STL的sort()函数 因此整体复杂度为O(nlogn)
struct student{
    char name[15];
    int score;
}item[1020];
bool cmp(student a,student b){
    if(a.score==b.score){
        return strcmp(a.name,b.name)==-1;
    }
    return a.score>b.score;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s %d",item[i].name,&item[i].score);
    }
    sort(item,item+n,cmp);
    for(int i=0;i<n;++i){
        printf("%s\n",item[i].name);
    }
    return 0;
}