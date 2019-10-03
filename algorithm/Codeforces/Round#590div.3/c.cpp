#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char pipe[2][200020];
int n;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",pipe[0]);
        scanf("%s",pipe[1]);
        int row=0;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(pipe[row][i]-'0'>2)
            {
                row=(row+1)%2;
                if(pipe[row][i]-'0'>2)
                {
                    continue;
                }
                else
                {
                    ans=-1;
                    break;
                }
            }
        }
        if(row!=1)
        {
            ans=-1;
        }
        if(ans==-1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}