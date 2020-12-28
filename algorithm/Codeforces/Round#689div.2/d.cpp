#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int dat[100020];
set<long long> checklist;
long long spilt(int l,int r){
    if(r<l){
        return 0;
    }
    int mid=(dat[l]+dat[r])/2;
    int pos=upper_bound(dat+l,dat+r+1,mid)-dat;
    long long res=0;
    if(pos>r){
        for(int i=l;i<=r;++i){
            res+=dat[i];
        }
        checklist.insert(res);
        return res;
    }
    res+=spilt(l,pos-1);
    res+=spilt(pos,r);
    checklist.insert(res);
    return res;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        checklist.clear();
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;++i){
            scanf("%d",&dat[i]);
        }
        sort(dat,dat+n);
        int left=0,right=n-1;
        checklist.insert(spilt(left,right));
        int tmp;
        for(int i=0;i<q;++i){
            scanf("%d",&tmp);
            if(checklist.count(tmp)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;
}