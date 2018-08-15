//二分问题，算是最小化最大值吧···自己加了好几个判断才过··注意二分结束条件和输出值是上限还是下限···
#include<stdio.h>
#include<iostream>
using namespace std;
const int INF=1e5;
int x[100020];
int N,M;
bool C(int n)
{
    int cnt=0,last=0;
    for(int i=0;i<N;i++)
    {
        if(x[i]>n)
        {
            return false;
        }
        if(last+x[i]>n)
        {
            cnt++;
            last=x[i];
        }
        else
        {
            last+=x[i];
        }
    }
    if(last>n)
    {
        return false;
    }
    cnt++;
    if(cnt<=M)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    while(cin>>N>>M)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d",&x[i]);
        }
    
        int lb=0,ub=INF;
        while(ub-lb>1)
        {
            int mid=(ub+lb)/2;
            if(C(mid))
            {
                ub=mid;
            }
            else
            {
                lb=mid;
            }
        }
        printf("%d\n",ub);
    }
    return 0;
}