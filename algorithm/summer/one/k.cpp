#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll card[100020];
ll score[100020];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M;
        scanf("%d%d",&N,&M);
        card[0]=0;
        for(int i=1;i<=N;++i)
        {
            ll tmp;
            scanf("%lld",&tmp);
            card[i]=card[i-1]+tmp;
        }
        for(int i=0;i<M;++i)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(l>r)
            {
                swap(l,r);
            }
            score[i]=card[r]-card[l-1];
        }
        sort(score,score+M);
        ll sum=0;
        for(int i=0;i<M;++i)
        {
            sum+=(i+1)*score[i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}