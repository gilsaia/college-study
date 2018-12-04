#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int save[2050];
const int mod=6e5;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&save[i]);
    }
    printf("%d\n1 %d %d\n",n+1,n,mod);
    for(int i=0;i<n;++i)
    {
        save[i]+=mod;
        printf("2 %d %d\n",i+1,save[i]-i-1);
    }
    return 0;
}