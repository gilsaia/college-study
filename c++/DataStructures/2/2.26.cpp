#include<vector>
using namespace std;
int find(vector<int> a,int n)
{
    if(n==1)
    {
        return a[0];
    }
    if(n==0)
    {
        return -1;
    }
    int pos=0;
    for(int i=1;i<n;i+=2)
    {
        if(a[i]==a[i-1])
        {
            a[pos]=a[i];
            pos++;
        }
    }
    int temp=find(a,pos);
    if(n&1&&temp==-1)
    {
        a[pos]=a[n-1];
        pos++;
        temp=find(a,pos);
    }
    return temp;
}