#include<cstdio>
#include<algorithm>
int main()
{
    double a[5];
    for(int i=0;i<5;++i)
    {
        scanf("%lf",&a[i]);
    }
    double ans=0;
    for(int i=0;i<5;++i)
    {
        ans=ans+((double)1/a[i]);
    }
    for(int i=0;i<5;++i)
    {
        for(int j=i+1;j<5;++j)
        {
            ans=ans-((double)1/(a[i]+a[j]));
        }
    }
    for(int i=0;i<5;++i)
    {
        for(int j=i+1;j<5;++j)
        {
            for(int m=j+1;m<5;++m)
            {
                ans=ans+((double)1/(a[i]+a[j]+a[m]));
            }
        }
    }
    for(int i=0;i<5;++i)
    {
        for(int j=i+1;j<5;++j)
        {
            for(int m=j+1;m<5;++m)
            {
                for(int n=m+1;n<5;++n)
                {
                    ans=ans-((double)1/(a[i]+a[j]+a[m]+a[n]));
                }
            }
        }
    }
    ans=ans+((double)1/(a[0]+a[1]+a[2]+a[3]+a[4]));
    printf("%.2lf\n",ans);
    return 0;
}