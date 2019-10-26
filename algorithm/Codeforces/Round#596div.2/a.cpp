#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==b)
    {
        a*=10;
        printf("%d %d\n",a,a+1);
    }
    else if((b-a)==1)
    {
        b*=10;
        printf("%d %d\n",b-1,b);
    }
    else if(a==9&&b==1)
    {
        printf("9 10\n");
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}