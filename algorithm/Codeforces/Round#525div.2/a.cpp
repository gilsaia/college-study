#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    int a=-1,b=-1;
    for(int i=1;i<=x;++i)
    {
        for(int j=1;j<=x;++j)
        {
            /*if(i==j)
            {
                continue;
            }*/
            int tmp=i*j;
            if(tmp>x)
            {
                break;
            }
            if(tmp*i>x)
            {
                a=tmp,b=i;
                break;
            }
        }
        if(a*b>x)
        {
            break;
        }
    }
    if(a==-1&&b==-1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d %d\n",a,b);
    }
    return 0;
}