#include<vector>
using namespace std;
//a
int max1(vector<int> a)
{
    int maxm=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>maxm)
        {
            maxm=a[i];
        }
    }
    return maxm*2;
}
//b
int max2(vector<int> a)
{
    int max=0,min=1e9,min2=1e9;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<min2)
        {
            min2=a[i];
        }
        if(a[i]>max)
        {
            max=a[i];
            min=min2;
        }
    }
    return max-min;
}
//c
int max3(vector<int> a)
{
    int maxm=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>maxm)
        {
            maxm=a[i];
        }
    }
    return maxm*maxm;
}
//d
int max4(vector<int> a)
{
    int max=0,min=1e9,min2=1e9;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<min2)
        {
            min2=a[i];
        }
        if(a[i]>max)
        {
            max=a[i];
            min=min2;
        }
    }
    return max/min;
}