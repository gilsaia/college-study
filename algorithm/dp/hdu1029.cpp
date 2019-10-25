#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int cnt=0,r=0;
        for(int i=0;i<n;++i)
        {
            int tmp;
            scanf("%d",&tmp);
            if(cnt==0)
            {
                r=tmp;
            }
            if(r==tmp)
            {
                ++cnt;
            }
            else
            {
                --cnt;
            }
        }
        printf("%d\n",r);
    }
    return 0;
}