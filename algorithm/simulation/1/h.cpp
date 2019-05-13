#include<cstdio>
using namespace std;
int findnum(int index,int &n)
{
    int res=0;
    if(index<=n)
    {
        ++res;
    }
    if(index*10>n)
    {
        return res;
    }
    index=index*10;
    for(int i=0;i<10;++i)
    {
        res+=findnum(index+i,n);
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int find=0,num=0;
        for(int i=1;i<10;++i)
        {
            int tmp=findnum(i,n);
            if(find+tmp>=k)
            {
                num=i;
                break;
            }
            else
            {
                find+=tmp;
            }
        }
        int index=num,tofind=k-find-1;
        while(tofind>0)
        {
            int tmp=0,tmpsum=0;
            for(int i=0;i<10;++i)
            {
                tmp=findnum(index*10+i,n);
                if(tmpsum+tmp>=tofind)
                {
                    index=index*10+i;
                    ++tmpsum;
                    break;
                }
                tmpsum+=tmp;
            }
            tofind-=tmpsum;
        }
        printf("%d\n",index);
    }
    return 0;
}