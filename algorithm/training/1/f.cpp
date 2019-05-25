#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
struct node
{
    long double value,point;
    bool operator<(const node &rhs) const
    {
        return point>rhs.point;
    }
};
int main()
{
    int n;
    cin>>n;
    priority_queue<node> que;
    for(int i=0;i<n;++i)
    {
        node tmp;
        cin>>tmp.point;
        if(tmp.point==0)
        {
            continue;
        }
        tmp.value=0;
        que.push(tmp);
    }
    while(que.size()>1)
    {
        node tmp1,tmp2;
        tmp1=que.top();
        que.pop();
        tmp2=que.top();
        que.pop();
        node sum;
        sum.point=tmp1.point+tmp2.point;
        sum.value=tmp1.value+tmp2.value+tmp1.point+tmp2.point;
        que.push(sum);
    }
    node tmp=que.top();
    cout.flags(ios::fixed);
    cout.precision(7);
    cout<<tmp.value<<endl;
    return 0;
}