//判断必胜态必败态后发现的神器规律···
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        if(n<=2)
        {
            printf("Alice\n");
        }    
        else
        {
            printf("Bob\n");
        }
    }
    return 0;
}