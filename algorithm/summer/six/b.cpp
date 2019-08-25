#include<cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    double sum=0;
    int time=0;
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp==-1)
        {
            continue;
        }
        sum+=tmp;
        ++time;
    }
    sum=sum/time;
    printf("%lf\n",sum);
    return 0;
}