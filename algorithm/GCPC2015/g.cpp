//判断是否递增即可
#include<stdio.h>
int main()
{
    int n,temp=0;
    scanf("%d",&n);
    bool pan=1;
    for(int i=0;i<n;i++)
    {
        int cmp;
        scanf("%d",&cmp);
        if(cmp<temp)
        {
            pan=0;
        }
        temp=cmp;
    }
    if(pan)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}