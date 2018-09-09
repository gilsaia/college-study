//书上例题···先试了平方分割结果tle···换成线段树好歹是ac了···emmmmmmmm还是在学习啊···
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int SIZE=(1<<18)-1;
int N,M;
int A[100010];
int I[5020],J[5020],K[5020];
int nums[100010];
vector<int> dat[SIZE];
void init(int k,int l,int r)
{
    if(r-l==1)
    {
        dat[k].push_back(A[l]);
    }
    else
    {
        int lch=k*2+1,rch=k*2+2;
        init(lch,l,(l+r)/2);
        init(rch,(l+r)/2,r);
        dat[k].resize(r-l);
        merge(dat[lch].begin(),dat[lch].end(),dat[rch].begin(),dat[rch].end(),dat[k].begin());
    }
}
int query(int i,int j,int x,int k,int l,int r)
{
    if(j<=l||r<=i)
    {
        return 0;
    }
    else if(i<=l&&r<=j)
    {
        return upper_bound(dat[k].begin(),dat[k].end(),x)-dat[k].begin();
    }
    else
    {
        int lc=query(i,j,x,k*2+1,l,(l+r)/2);
        int rc=query(i,j,x,k*2+2,(l+r)/2,r);
        return lc+rc;
    }
}
void solve()
{
    for(int i=0;i<N;i++)
    {
        nums[i]=A[i];
    }
    sort(nums,nums+N);
    init(0,0,N);
    for(int i=0;i<M;i++)
    {
        int l=I[i],r=J[i]+1,k=K[i];
        int lb=-1,ub=N-1;
        while(ub-lb>1)
        {
            int md=(ub+lb)/2;
            int c=query(l,r,nums[md],0,0,N);
            if(c>=k)
            {
                ub=md;
            }
            else
            {
                lb=md;
            }
        }
        printf("%d\n",nums[ub]);
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&I[i],&J[i],&K[i]);
        --I[i];
        --J[i];
    }
    solve();
    return 0;
}