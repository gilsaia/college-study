#include<cstdio>
#include<algorithm>
using namespace std;
int dis[1200],wei[1200];
typedef long long ll;
int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    int negsi=N;
    for(int i=0;i<N;++i)
    {
        scanf("%d%d",&dis[i],&wei[i]);
        if(negsi==N&&dis[i]>0)
        {
            negsi=i;
        }
    }
    ll ans=0;
    for(int i=0;i<negsi;++i)
    {
        ans+=wei[i]/K*(dis[i]*-1)*2;
        if(wei[i]%K!=0)
        {
            ans+=(dis[i]*-1)*2;
            int lef=K-wei[i]%K;
            for(int j=i+1;j<negsi;++j)
            {
                if(wei[j]>=lef)
                {
                    wei[j]-=lef;
                    break;
                }
                else
                {
                    lef-=wei[j];
                    wei[j]=0;
                }
            }
        }
    }
    for(int i=N-1;i>=negsi;--i)
    {
        ans+=wei[i]/K*dis[i]*2;
        if(wei[i]%K!=0)
        {
            ans+=dis[i]*2;
            int lef=K-wei[i]%K;
            for(int j=i-1;j>=negsi;--j)
            {
                if(wei[j]>=lef)
                {
                    wei[j]-=lef;
                    break;
                }
                else
                {
                    lef-=wei[j];
                    wei[j]=0;
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}