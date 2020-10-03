#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxnode = 1<<19;

int _max, op, qL, qR, v;

struct IntervalTree {
  int maxv[maxnode], setv[maxnode];

  // 维护信息
  void maintain(int o, int L, int R) {
    int lc = o*2, rc = o*2+1;
    if(R > L) {
      maxv[o] = max(maxv[lc], maxv[rc]);
    }
    if(setv[o] >= 0) { maxv[o] = setv[o]; }
  }

  // 标记传递
  void pushdown(int o) {
    int lc = o*2, rc = o*2+1;
    if(setv[o] >= 0) { //本结点有标记才传递。注意本题中set值非负，所以-1代表没有标记
      setv[lc] = setv[rc] = setv[o];
      setv[o] = -1; // 清除本结点标记
    }
  }

  void update(int o, int L, int R) {
    int lc = o*2, rc = o*2+1;
    if(qL <= L && qR >= R) { // 标记修改
      setv[o] = v;
    } else {
      pushdown(o);
      int M = L + (R-L)/2;
      if(qL <= M) update(lc, L, M); else maintain(lc, L, M);
      if(qR > M) update(rc, M+1, R); else maintain(rc, M+1, R);
    }
    maintain(o, L, R);
  }

  void query(int o, int L, int R) {
    if(setv[o] >= 0) { // 递归边界1：有set标记
      _max = max(_max, setv[o]);
    } else if(qL <= L && qR >= R) { // 递归边界2：边界区间
      _max = max(_max, maxv[o]);
    } else { // 递归统计
      int M = L + (R-L)/2;
      if(qL <= M) query(o*2, L, M);
      if(qR > M) query(o*2+1, M+1, R);
    }
  }
};

const int INF = 1000000000;

IntervalTree tree;

struct section{
    int start,end,color;
    long long bonus;
};
section line[300020];
bool cmp(section a,section b){
    if(a.end==b.end){
        return a.start<b.start;
    }
    return a.end<b.end;
}
long long dp[300020][2],colorsum[2][300020],effect[300020][2],bonus[300020][2],lookahead[300020][2];
int main(){
    memset(&tree, 0, sizeof(tree));
    memset(tree.setv, -1, sizeof(tree.setv));
    tree.setv[1] = 0;
    int n,m;
    scanf("%d%d",&n,&m);
    v=0,qL=1,qR=n;
    tree.update(1,1,n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&effect[i][0]);
        colorsum[0][i]=colorsum[0][i-1]+effect[i][0];
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&effect[i][1]);
        colorsum[1][i]=colorsum[1][i-1]+effect[i][1];
    }
    for(int i=0;i<m;++i){
        scanf("%d%d%d%lld",&line[i].color,&line[i].start,&line[i].end,&line[i].bonus);
        --line[i].color;
    }
    sort(line,line+m,cmp);
    int cursec=0;
    for(int i=1;i<=n;++i){
        bool change[2]={false,false};
        while(line[cursec].end==i){
            section cur=line[cursec];
            long long tmpscore=max(dp[cur.start-1][0],dp[cur.start-1][1])+colorsum[cur.color][cur.end]-colorsum[cur.color][cur.start-1]+cur.bonus;
            int findlastpos=cur.end-1;
            qL=cur.start,qR=cur.end-1;
            tree.query(1,1,n);
            while(_max!=0){
                tmpscore=max(tmpscore,max(dp[_max-1][0],dp[_max-1][1])+colorsum[cur.color][cur.end]-colorsum[cur.color][_max-1]+cur.bonus+bonus[cur.end-1][cur.color]-bonus[_max-1][cur.color]);
                qL=_max,qR=_max;
                tree.query(1,1,n);
            }
            if(!change[cur.color]){
                dp[i][cur.color]=tmpscore;
                change[cur.color]=true;
            }else{
                dp[i][cur.color]=max(dp[i][cur.color],tmpscore);
            }
            bonus[cur.end][cur.color]=max(bonus[cur.end][cur.color],bonus[cur.end-1][cur.color]+cur.bonus);
            v=cur.start,qL=cur.start+1,qR=cur.end-1;
            tree.update(1,1,n);
            ++cursec;
        }
        long long tmpscore=max(dp[i-1][0],dp[i-1][1]);
        if(!change[0]){
            dp[i][0]=tmpscore+effect[i][0];
            change[0]=true;
        }else{
            dp[i][0]=max(dp[i][0],tmpscore+effect[i][0]);
        }
        if(!change[1]){
            dp[i][1]=tmpscore+effect[i][1];
            change[1]=true;
        }else{
            dp[i][1]=max(dp[i][1],tmpscore+effect[i][1]);
        }
        bonus[i][0]=max(bonus[i-1][0],bonus[i][0]);
        bonus[i][1]=max(bonus[i-1][1],bonus[i][1]);
    }
    printf("%lld\n",max(dp[n][0],dp[n][1]));
    return 0;
}