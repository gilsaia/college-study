//依旧是尺取法样题···emmmmmmmmpoj又炸了所以暂时不知道对不对···不过看题解思路是差不多的应该没问题···
#include<stdio.h>
#include<vector>
using namespace std;
struct save
{
    long long num,l,r;
};
vector<save> dat;
int main()
{
    long long n;
    scanf("%lld",&n);
    long long l=1,r=1,cnt=0,sum=0;
    for(;;)
    {
        while(sum<n)
        {
            sum+=r*r;
            r++;
        }
        if(sum==n)
        {
            cnt++;
            save temp;
            temp.l=l;
            temp.r=r;
            temp.num=r-l;
            dat.push_back(temp);
        }
        sum-=l*l;
        l++;
        if(l*l>n)
        {
            break;
        }
    }
    printf("%lld\n",cnt);
    for(int i=0;i<dat.size();i++)
    {
        printf("%lld",dat[i].num);
        long long ther=dat[i].r;
        for(long long j=dat[i].l;j<ther;j++)
        {
            printf(" %lld",j);
        }
        printf("\n");
    }
    return 0;
}