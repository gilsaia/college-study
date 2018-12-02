#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,S;
    scanf("%d%d",&n,&S);
    int ans=S/n;
    if(S%n)
    {
        ++ans;
    }
    printf("%d\n",ans);
    return 0;
}