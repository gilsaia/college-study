#include<cstdio>
#include<algorithm>
using namespace std;
int res[150020];
bool test(int n)
{
    while(n)
    {
        if(n<10)
        {
            if(n==1||n==7)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            int res=0;
            while(n)
            {
                res+=(n%10)*(n%10);
                n/=10;
            }
            n=res;
        }
    }
}
int main()
{
    int num=0;
    for(int i=1;num<150020;++i)
    {
        if(test(i))
        {
            res[num]=i;
            ++num;
        }
    }
    int Q;
    scanf("%d",&Q);
    for(int i=0;i<Q;++i)
    {
        int j;
        scanf("%d",&j);
        printf("%d\n",res[j-1]);
    }
    return 0;
}