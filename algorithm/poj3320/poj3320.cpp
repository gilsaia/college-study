//尺取法例题···似乎有更高效的算法···或者是我优化太差了···
#include<stdio.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int P;
int a[1000010];
int main()
{
    scanf("%d",&P);
    for(int i=0;i<P;i++)
    {
        scanf("%d",&a[i]);
    }
    set<int> save;
    for(int i=0;i<P;i++)
    {
        save.insert(a[i]);
    }
    int n=save.size();
    int s=0,t=0,num=0;
    map<int,int> count;
    int res=P;
    for(;;)
    {
        while(t<P&&num<n)
        {
            if(count[a[t++]]++==0)
            {
                num++;
            }
        }
        if(num<n)
        {
            break;
        }
        res=min(res,t-s);
        if(--count[a[s++]]==0)
        {
            num--;
        }
    }
    printf("%d\n",res);
    return 0;
}