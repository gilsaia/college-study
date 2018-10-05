//emmmmmm还是看思路的题···
#include<cstdio>
#include<map>
using namespace std;
int n,m,dx,dy,cnt[1000100];
int main()
{
    scanf("%d%d%d%d",&n,&m,&dx,&dy);
    map<int,int> tocnt;
    int tmpx=0,tmpy=0;
    for(int i=0;i<n;++i)
    {
        tocnt[tmpx]=tmpy;
        tmpx+=dx,tmpy+=dy;
        tmpx%=n;
        tmpy%=n;
    }
    for(int i=0;i<m;++i)
    {
        int appx,appy;
        scanf("%d%d",&appx,&appy);
        ++cnt[(appy+n-tocnt[appx])%n];
    }
    int ans=0,res=0;
    for(int i=0;i<n;++i)
    {
        if(cnt[i]>res)
        {
            res=cnt[i];
            ans=i;
        }
    }
    printf("%d %d\n",0,ans);
    return 0;
}