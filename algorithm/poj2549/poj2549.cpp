//说是折半枚举的题实际也没那么做···emmmmmmmm反正看了题解之后这个奇怪的做法是能ac了···
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        ll num[1030];
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&num[i]);
        }
        sort(num,num+n);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==j)
                {
                    continue;
                }
                int right=j-1,left=0;
                ll tmp=num[i]-num[j];
                while(left<right)
                {
                    if(tmp>num[right]+num[left])
                    {
                        left++;
                    }
                    else if(tmp<num[right]+num[left])
                    {
                        right--;
                    }
                    else
                    {
                        printf("%lld\n",num[i]);
                        goto L1;
                    }
                }
            }
        }
        printf("no solution\n");
        L1:;
    }
    return 0;
}