#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 0;
const int maxnode = 1<<20;

int op, qL, qR, p, v;  //qL和qR为全局变量，询问区间[qL,qR];

struct IntervalTree {
  int minv[maxnode];

  void update(int o, int L, int R) {
    int M = L + (R-L)/2;
    if(L == R) minv[o] = v; // 叶结点，直接更新minv
    else {
      // 先递归更新左子树或右子树
      if(p <= M) update(o*2, L, M); else update(o*2+1, M+1, R);
      // 然后计算本结点的minv
      minv[o] = minv[o*2]|minv[o*2+1];
    }
  }

  int query(int o, int L, int R) {
    int M = L + (R-L)/2, ans = 0;
    if(qL <= L && R <= qR) return minv[o]; // 当前结点完全包含在查询区间内
    if(qL <= M) ans |= query(o*2, L, M); // 往左走
    if(M < qR) ans |= query(o*2+1, M+1, R); // 往右走
    return ans;
  }
};
IntervalTree tree;
char str[100020];
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;str[i]!='\0';++i)
    {
        p=i+1,v=1<<(str[i]-'a');
        tree.update(1,1,len);
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int num;
            char tmp;
            scanf("%d %c",&num,&tmp);
            p=num,v=1<<(tmp-'a');
            tree.update(1,1,len);
        }
        else
        {
            scanf("%d%d",&qL,&qR);
            int sum=tree.query(1,1,len);
            int ans=0;
            for(int i=0;i<26;++i)
            {
                if((sum>>i)&1)
                {
                    ++ans;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}