#include<cstdio>
#include<algorithm>
using namespace std;
int pos[200050];
int main()
{
    int n;
    scanf("%d",&n);
    int lower=0;
    for(int i=1;i<=n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        pos[tmp]=i;
    }
    for(int i=0;i<n;++i)
    {
        int find,ans=0;
        scanf("%d",&find);
        int postmp=pos[find];
        if(postmp<=lower)
        {
            ans=0;
        }
        else
        {
            ans=postmp-lower;
            lower=postmp;
        }
        printf("%d%c",ans,i!=n-1?' ':'\n');
    }
    return 0;
}