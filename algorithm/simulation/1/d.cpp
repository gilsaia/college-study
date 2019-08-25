#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll MOD=1e9+7;
ll bits[100020],m,fir[100020],sec[100020],type[100020];
struct node{
    ll index,value;
};
node save[100020];
bool cmp(node a,node b)
{
    return a.value<b.value;
}
ll sum(int i)
{
    ll s=0;
    while(i>0)
    {
        s+=bits[i];
        i-=i&-i;    
    }
    return s;
}
void add(int i,ll x)
{
    while(i<=(m+1))
    {
        bits[i]+=x;
        i+=i&-i;    
    }
}
int main()
{
    int Q;
    scanf("%d",&Q);
    for(int i=0;i<Q;++i)
}