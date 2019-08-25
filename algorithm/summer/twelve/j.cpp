#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int cal(int one,int two)
{
    if(one<(n-2))
    {
        return 0;
    }
    if(one==n)
    {
        return n%3;
    }
    if(one==(n-1))
    {
        return 1;
    }
    if(two&&((n%3)!=2))
    {
        return 1;
    }
    return 0;
}
int main()
{
    int cnt[2];
    cnt[0]=cnt[1]=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp==1)
        {
            ++cnt[0];
        }
        else if(tmp==2)
        {
            ++cnt[1];
        }
    }
    int res=cal(cnt[0],cnt[1]);
    if(res)
    {
        printf("Win\n");
    }
    else
    {
        printf("Lose\n");
    }
    return 0;
}