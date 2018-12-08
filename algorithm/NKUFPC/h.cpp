#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cmp[100020];
int main()
{
    cout<<99999<<endl;
    int mid=(99999-1)/2;
    int num=mid,element=0;
    for(;num<100000;++num)
    {
        cmp[num]=element++;
        cmp[num-mid]=element++;
    }
    cout<<cmp[0];
    for(int i=1;i<100000-1;++i)
    {
        cout<<" "<<cmp[i];
    }
    cout<<endl;
    return 0;
}