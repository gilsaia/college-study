#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct tosort
{
    string value;
    int num;
};
bool cmp(tosort a,tosort b)
{
    return a.value<b.value;
}
int main()
{
    int L;
    cin>>L;
    tosort ddd[120];
    for(int i=0;i<L;++i)
    {
        cin>>ddd[i].value;
        ddd[i].num=i;
    }
    sort(ddd,ddd+L,cmp);
    tosort sorted[120];
    for(int i=0;i<L;++i)
    {
        sorted[ddd[i].num].num=i;
    }
    for(int i=0;i<L;++i)
    {
        cout<<" "<<sorted[i].num;
    }
    return 0;
}