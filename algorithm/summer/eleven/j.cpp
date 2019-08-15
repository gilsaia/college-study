#include<cstdio>
#include<algorithm>
int a[5];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        a[0]=a[1]=a[2]=0;
        for(int i=0;i<n*2;++i)
        {
            int tmp;
            scanf("%d",&tmp);
            ++a[tmp%3];
        }
        if(a[0]>n)
        {
            printf("NO\n");
        }
        else
        {
            if(a[0]<=1&&a[1]&&a[2])
            {
                printf("NO\n");
                continue;
            }
            if(a[0]==2&&a[1]&&a[2]&&a[1]%2==0&&a[2]%2==0)
            {
                printf("NO\n");
                continue;
            }
            printf("YES\n");
        }
    }
    return 0;
}