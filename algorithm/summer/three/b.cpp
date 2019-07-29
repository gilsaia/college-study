#include<cstdio>
#include<algorithm>
using namespace std;
int Gcd(int a, int b)
{
    if(b == 0)
        return a;
    return Gcd(b, a % b);
}
int main()
{
    int q,p,s;
    scanf("%d%d%d",&p,&q,&s);
    int ans=0;
    for(int i=p;i<=s;i+=p)
    {
        if(i%q==0)
        {
            printf("yes\n");
            return 0;
        }
    }
    printf("no\n");
    return 0;
    // if(ans<=s)
    // {
    //     printf("yes\n");
    // }
    // else
    // {
    //     printf("no\n");
    // }
    // return 0;
}