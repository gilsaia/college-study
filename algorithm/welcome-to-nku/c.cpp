#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    --n;
    int is=0,last=0,num=0,tmp=0;
    scanf("%d",&is);
    last=is;
    tmp++;
    while(n--)
    {
        scanf("%d",&is);
        if(is<=2*last)
        {
            tmp++;
            last=is;
        }
        else
        {
            num=max(num,tmp);
            last=is;
            tmp=1;
        }
    }
    num=max(num,tmp);
    printf("%d\n",num);
    return 0;
}