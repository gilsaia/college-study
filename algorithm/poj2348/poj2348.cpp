//一样找出必胜态必败态的神奇方法···
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b),a&&b)
    {
        bool f=true;
        while(true)
        {
            if(a>b)
            {
                swap(a,b);
            }
            if(b%a==0)
            {
                break;
            }
            if(b-a>a)
            {
                break;
            }
            b-=a;
            f=!f;
        }
        if(f)
        {
            printf("Stan wins\n");
        }
        else
        {
            printf("Ollie wins\n");
        }
    }
    return 0;
}