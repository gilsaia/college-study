#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cmp[100020];
void toin(int left,int right,int minele)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        for(int i=mid;i<=right;++i)
        {
            cmp[i]=minele++;
        }
        toin(left,mid-1,minele);
    }
    else
    {
        cmp[left]=minele;
    }
}
int main()
{
    cout<<100000<<endl;
    toin(0,100000-1,0);
    cout<<cmp[0];
    for(int i=1;i<100000;++i)
    {
        cout<<" "<<cmp[i];
    }
    cout<<endl;
    return 0;
}