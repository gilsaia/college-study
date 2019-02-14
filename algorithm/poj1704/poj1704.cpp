//nim···nim数···
#include<cstdio>
#include<algorithm>
using namespace std;
int stone[1020];
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;++j)
        {
            scanf("%d",&stone[j]);
        }
        if(n%2==1)
        {
            stone[n++]=0;
        }
        sort(stone,stone+n);
        int x=0;
        for(int j=0;j+1<n;j+=2)
        {
            x^=(stone[j+1]-stone[j]-1);
        }
        if(x==0)
        {
            printf("Bob will win\n");
        }
        else
        {
            printf("Georgia will win\n");
        }
    }
    return 0;
}