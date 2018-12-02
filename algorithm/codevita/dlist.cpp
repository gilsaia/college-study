#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
bool order(vector<int> &check)
{
    for(int i=1;i<check.size();++i)
    {
        if(check[i]==check[i-1]+1)
        {
            return false;
        }
    }
    return true;
}
bool trease(vector<int> &check)
{
    for(int i=1;i<check.size();++i)
    {
        if(check[i]==check[i-1]-1)
        {
            continue;
        }
        return true;
    }
    return false;
}
void find(int n,ostream &out)
{
    vector<int> check;
    for(int i=1;i<=n;++i)
    {
        check.push_back(i);
    }
    int ans=0;
    while(trease(check))
    {
        if(order(check))
        {
            ++ans;
        }
        int pos=-1,prev=-1;
        for(int i=check.size()-2;i>=0;--i)
        {
            if(check[i]<check[i+1])
            {
                pos=i;
                break;
            }
        }
        for(int i=check.size()-1;i>pos;--i)
        {
            if(check[i]>check[pos])
            {
                prev=i;
                break;
            }
        }
        swap(check[pos],check[prev]);
        for(int i=pos+1,j=check.size()-1;i<j;++i,--j)
        {
            swap(check[i],check[j]);
        }
    }
    if(order(check))
    {
        ++ans;
    }
    out<<ans<<endl;
}
int main()
{
    ofstream out("out.txt");
    for(int i=1;i<=10;++i)
    {
        find(i,out);
    }
    return 0;
}