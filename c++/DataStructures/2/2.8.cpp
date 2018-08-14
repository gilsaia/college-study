//已知randInt(i,j)以相同的概率生成i到j的随机数
int randInt(int i,int j);
#include<algorithm>
int a[100000000],used[100000000];
void function1(int n)
{
    for(int i=0;i<n;i++)
    {
L1:     int temp=randInt(1,n);
        for(int j=0;j<i;j++)
        {
            if(a[j]==temp)
            {
                goto L1;
            }
        }
        a[i]=temp;
    }
}
void function2(int n)
{
    for(int i=0;i<n;i++)
    {
        int temp=randInt(1,n);
        while(used[temp])
        {
            temp=randInt(1,n);
        }
        a[i]=temp;
        used[temp]=1;
    }
}
void function3(int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(int i=1;i<n;i++)
    {
        std::swap(a[i],a[randInt(0,i)]);
    }
}