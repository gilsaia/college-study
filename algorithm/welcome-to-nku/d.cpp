//思路没想对···找到题解了···
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
const int INF=0x3f3f3f3f;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<=b;i++)
 
//bool cmpup(node a,node b)
//{
//    return a.l<b.l;
//}
//bool cmpdown(node a,node b)
//{
//    return a.r<b.r;
//}
struct noder
{
    int val;
    int id;
    bool operator <(const noder&a) const{
        return val > a.val;
    }
};
struct nodel
{
    int val,id;
     bool operator < (const nodel &b)const
    {
        return val<b.val;
    }
};
nodel l;
noder r;
priority_queue<nodel>pl;//注意两个结构体都需要进行重载
priority_queue<noder>pr;
int main()
{
   int n;
   cin>>n;
   rep(i,1,n)
   {
       cin>>l.val;
       cin>>r.val;
       l.id=i;
       r.id=i;
        pl.push(l);
        pr.push(r);
   }
   if(pl.top().id==pr.top().id)
   {
       pr.pop();pl.pop();
       cout<<max(0,pr.top().val-pl.top().val);return 0;
   }
   int ans1=pl.top().val;
   int ans2=pr.top().val;
   pl.pop();pr.pop();
   cout<<max(0,max(pr.top().val-ans1,ans2-pl.top().val));
}
