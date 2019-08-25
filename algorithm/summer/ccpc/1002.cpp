#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#define LC o << 1
#define RC o << 1 | 1
using namespace std;
const int maxn = 1000010;
int n, m, a[maxn], u[maxn], x[maxn], l[maxn], r[maxn], k[maxn], cur, cur1, cur2,
    q1[maxn], q2[maxn], v[maxn];
char op[maxn];
set<int> ST;
map<int, int> mp;
struct segment_tree  //封装的动态开点权值线段树
{
  int cur, rt[maxn * 4], sum[maxn * 60], lc[maxn * 60], rc[maxn * 60];
  void build(int& o) { o = ++cur; }
  void print(int o, int l, int r) {
    if (!o) return;
    if (l == r && sum[o]) printf("%d ", l);
    int mid = (l + r) >> 1;
    print(lc[o], l, mid);
    print(rc[o], mid + 1, r);
  }
  void update(int& o, int l, int r, int x, int v) {
    if (!o) o = ++cur;
    sum[o] += v;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (x <= mid)
      update(lc[o], l, mid, x, v);
    else
      update(rc[o], mid + 1, r, x, v);
  }
} st;
//树状数组实现
inline int lowbit(int o) { return (o & (-o)); }
void upd(int o, int x, int v) {
  for (; o <= n; o += lowbit(o)) st.update(st.rt[o], 1, n, x, v);
}
void gtv(int o, int* A, int& p) {
  p = 0;
  for (; o; o -= lowbit(o)) A[++p] = st.rt[o];
}
int qry(int l, int r, int k) {
  if (l == r) return l;
  int mid = (l + r) >> 1, siz = 0;
  for (int i = 1; i <= cur1; i++) siz += st.sum[st.lc[q1[i]]];
  for (int i = 1; i <= cur2; i++) siz -= st.sum[st.lc[q2[i]]];
  // printf("j %d %d %d %d\n",cur1,cur2,siz,k);
  if (siz >= k) {
    for (int i = 1; i <= cur1; i++) q1[i] = st.lc[q1[i]];
    for (int i = 1; i <= cur2; i++) q2[i] = st.lc[q2[i]];
    return qry(l, mid, k);
  } else {
    for (int i = 1; i <= cur1; i++) q1[i] = st.rc[q1[i]];
    for (int i = 1; i <= cur2; i++) q2[i] = st.rc[q2[i]];
    return qry(mid + 1, r, k - siz);
  }
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        ST.clear();
        cur=cur1=cur2=0;
        memset(a,0,sizeof(a));
        memset(u,0,sizeof(u));
        memset(x,0,sizeof(x));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(k,0,sizeof(k));
        memset(q1,0,sizeof(q1));
        memset(q2,0,sizeof(q2));
        memset(v,0,sizeof(v));
        memset(&st,0,sizeof(st));
        for(int i=1;i<=n;++i)
        {
            scanf("%d",a+i);
            ST.insert(a[i]);
        }
        for(set<int>::iterator it=ST.begin();it!=ST.end();++it)
        {
            mp[*it]=++cur;v[cur]=*it;
        }
        for(int i=1;i<=n;++i)
        {
            a[i]=mp[a[i]];
        }
        for(int i=1;i<=n;++i)
        {
            upd(i,a[i],1);
        }
        int lastans=0;
        for(int i=0;i<m;++i)
        {
            int op;
            scanf("%d",&op);
            if(op==1)
            {
                int num;
                scanf("%d",&num);
                num^=lastans;
                upd(num,a[num],-1);
            }
            else
            {
                int thisl,thisk;
                scanf("%d%d",&thisl,&thisk);
                thisl^=lastans,thisk^=lastans;
                gtv(n,q1,cur1);
                gtv(thisl,q2,cur2);
                int fir=1,end=n-thisl;
                int ans=0x3f3f3f3f;
                while(fir<=end)
                {
                    int mid=(fir+end)/2;
                    int inde=qry(1,n,mid);
                    if(v[inde]>=thisk)
                    {
                        end=mid-1;
                    }
                    else
                    {
                        fir=mid+1;
                    }
                    ans=min(ans,v[inde]);
                }
                printf("%d\n",ans);
                lastans=ans;
            }
        }
    }
//   scanf("%d%d", &n, &m);
//   for (int i = 1; i <= n; i++) scanf("%d", a + i), ST.insert(a[i]);
//   for (int i = 1; i <= m; i++) {
//     scanf(" %c", op + i);
//     if (op[i] == 'C')
//       scanf("%d%d", u + i, x + i), ST.insert(x[i]);
//     else
//       scanf("%d%d%d", l + i, r + i, k + i);
//   }
//   for (set<int>::iterator it = ST.begin(); it != ST.end(); it++)
//     mp[*it] = ++cur, v[cur] = *it;
//   for (int i = 1; i <= n; i++) a[i] = mp[a[i]];
//   for (int i = 1; i <= m; i++)
//     if (op[i] == 'C') x[i] = mp[x[i]];
//   n += m;
//   // build(1,1,n);
//   for (int i = 1; i <= n; i++) upd(i, a[i], 1);
//   // print(1,1,n);
//   for (int i = 1; i <= m; i++) {
//     if (op[i] == 'C') {
//       upd(u[i], a[u[i]], -1);
//       upd(u[i], x[i], 1);
//       a[u[i]] = x[i];
//     } else {
//       gtv(r[i], q1, cur1);
//       gtv(l[i] - 1, q2, cur2);
//       printf("%d\n", v[qry(1, n, k[i])]);
//     }
//   }
  return 0;
}