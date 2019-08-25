#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100020;
int cnt[MAXN],sum[MAXN],len[MAXN];
struct Seg
{
    int l,r,h,d;
    Seg(){}
    Seg(int _l,int _r,int _h,int _d) {l = _l,r = _r,h = _h,d = _d;}
    bool operator < (const Seg &rhs) const
    {
        return h < rhs.h;
    }
}a[MAXN];
void build(int l,int r,int rt)
{
    cnt[rt] = sum[rt] = 0;
    len[rt] = r - l + 1;
    if(l == r) return ;
    int mid =(l + r)>> 1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
}
void update_rev(int rt)
{
    cnt[rt] ^= 1;
    sum[rt] = len[rt] - sum[rt];
}
void push_down(int rt)
{
    if(cnt[rt])
    {
        update_rev(rt<<1);
        update_rev(rt<<1|1);
        cnt[rt] = 0;
    }
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L <=l && r <= R)
    {
        update_rev(rt);
        return ;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if(L <= mid) update(L,R,c,l,mid,rt<<1);
    if(R > mid) update(L,R,c,mid+1,r,rt<<1|1);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,K;
        scanf("%d%d",&N,&K);
        int size=0;
        for(int i=0;i<K;++i)
        {
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
            a[size++]=Seg(x1,x2,y1,1);
            if(y2<N)
            {
                a[size++]=Seg(x1,x2,y2+1,-1);
            }
        }
        sort(a,a+size);
        build(1,N,1);
        int ans=0;
        int num=0;
        for(int i=1;i<=N;++i)
        {
            while (num<size&&a[num].h==i)
            {
                update(a[num].l,a[num].r,1,1,N,1);
                ++num;
            }
            ans+=sum[1];
        }
        printf("%d\n",ans);
    }
    return 0;
}