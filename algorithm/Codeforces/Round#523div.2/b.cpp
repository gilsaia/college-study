#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
bool cmp(int a,int b)
{
    return a>b;
}
int exihi[100020];
int main()
{
    int n,m;
    ll sum=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&exihi[i]);
        sum+=exihi[i];
    }
    sort(exihi,exihi+n);
    ll ans=0,max=0,used=0;
    used+=exihi[0]-1;
    for(int i=1;i<n;++i)
    {
        if(exihi[i]==exihi[i-1])
        {
            if(used>0)
            {
                --used;
            }
        }
        else
        {
            used+=exihi[i]-exihi[i-1]-1;
        }
    }
    used+=n;
    ans=sum-used;
    printf("%I64d\n",ans);
    return 0;
}