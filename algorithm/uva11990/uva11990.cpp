//动态求逆序数·····找了半天好几个线段树套树的实在看不懂···找的这个平方分割方法的···
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
const int BUCKETSIZE=450;
int A[MAXN],N,M;
struct Bucket
{
    int count;
    int prefix_sum;
}bucket[BUCKETSIZE][BUCKETSIZE];
struct space
{
    int X[MAXN],Y[MAXN];
    void insert(const int &x,const int &y)
    {
        X[y]=x;
        Y[x]=y;
    }
    void remove(const int &x,const int &y)
    {
        X[y]=-1;
        Y[x]=-1;
    }
    int getX(const int &y)
    {
        return X[y];
    }
    int getY(const int &x)
    {
        return Y[x];
    }
    void init()
    {
        memset(X,-1,sizeof(X));
        memset(Y,-1,sizeof(Y));
    }
}space;
void updateprefixsum(int bx,int by)
{
    int sum=(bx>0?bucket[bx-1][by].prefix_sum:0);
    for(int i=bx;i<BUCKETSIZE;i++)
    {
        sum+=bucket[i][by].count;
        bucket[i][by].prefix_sum=sum;
    }
}
void add(int x,int y)
{
    space.insert(x,y);
    int bx=x/BUCKETSIZE;
    int by=y/BUCKETSIZE;
    ++bucket[bx][by].count;
    updateprefixsum(bx,by);
}
void remove(int x,int y)
{
    space.remove(x,y);
    int bx=x/BUCKETSIZE;
    int by=y/BUCKETSIZE;
    --bucket[bx][by].count;
    updateprefixsum(bx,by);
}
int countsum(int x,int y)
{
    int blockw=(x+1)/BUCKETSIZE;
    int blockh=(y+1)/BUCKETSIZE;
    int count=0;
    for(int i=0;i<blockh;++i)
    {
        if(blockw>0)
        {
            count+=bucket[blockw-1][i].prefix_sum;
        }
    }
    for(int i=blockw*BUCKETSIZE;i<=x;i++)
    {
        if(space.getY(i)!=-1&&space.getY(i)<blockh*BUCKETSIZE)
        {
            count++;
        }
    }
    for(int i=blockh*BUCKETSIZE;i<=y;++i)
    {
        if(space.getX(i)!=-1&&space.getX(i)<=x)
        {
            count++;
        }
    }
    return count;
}
int count_inversion(int x,int y)
{
    int count=0;
    int intersection=countsum(x,y);
    count+=countsum(x,N-1)-intersection;
    count+=countsum(N-1,y)-intersection;
    return count;
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        space.init();
        memset(bucket,0,sizeof(bucket));
        for(int i=0;i<N;++i)
        {
            scanf("%d",&A[i]);
            --A[i];
        }
        long long inversion=0;
        for(int i=0;i<N;++i)
        {
            add(i,A[i]);
            inversion+=count_inversion(i,A[i]);
        }
        for(int i=0;i<M;++i)
        {
            int q;
            scanf("%d",&q);
            --q;
            printf("%lld\n",inversion);
            inversion-=count_inversion(space.getX(q),q);
            remove(space.getX(q),q);
        }
    }
    return 0;
}