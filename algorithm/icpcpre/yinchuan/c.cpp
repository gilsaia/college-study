#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
struct people
{
    int a,b,num;
};
bool cmpa(people a,people b)
{
    return a.a>b.a;
}
bool cmpb(people a,people b)
{
    return a.b>b.b;
}
people a[210],b[210];
int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d",&a[i].a,&a[i].b);
            a[i].num=i+1;
            b[i]=a[i];
        }
        sort(a,a+n,cmpa);
        sort(b,b+n,cmpb);
        set<int> sel;
        for(int i=0;i<8;++i)
        {
            sel.insert(a[i].num);
            sel.insert(b[i].num);
        }
        int t=8;
        int cur=16;
        int siz=sel.size();
        int add=cur-siz;
        while(add)
        {
            cur+=(2*add);
            for(int i=0;i<add;i++)
            {
                sel.insert(a[i+t].num);
                sel.insert(b[i+t].num);
            }
            t+=add;
            siz=sel.size();
            add=cur-siz;
        }
    }
}