#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node
{
    ll count;
    node *next[2];
    node()
    {
        count=0;
        next[0]=next[1]=NULL;
    }
};
node A,res;
int digit=19;
void inserta(int &value,int dig,node *now)
{
    int t=(value>>(dig-1))&1;
    if(now->next[t]==NULL)
    {
        now->next[t]=new node;
    }
    ++now->count;
    if(dig>0)
    {
        inserta(value,dig-1,now->next[t]);
    }
}
ll insertans(int &value,int dig,node *resno,node *ano)
{
    if(dig==0)
    {
        resno->count+=ano->count;
        return ano->count;
    }
    int t=(value>>(dig-1))&1;
    if(resno->next[1]==NULL)
    {
        resno->next[1]=new node;
    }
    if(resno->next[0]==NULL)
    {
        resno->next[0]=new node;
    }
    if(ano->next[1]==NULL)
    {
        ano->next[1]=new node;
    }
    if(ano->next[0]==NULL)
    {
        ano->next[1]=new node;
    }
    if(t==1)
    {
        ll toadd1=insertans(value,dig-1,resno->next[1],ano->next[1]);
        ll toadd2=insertans(value,dig-1,resno->next[1],ano->next[0]);
        ll sum=toadd1+toadd2;
        resno->count+=sum;
        return sum;
    }
    else
    {
        ll toadd1=insertans(value,dig-1,resno->next[1],ano->next[1]);
        ll toadd2=insertans(value,dig-1,resno->next[0],ano->next[0]);
        ll sum=toadd1+toadd2;
        resno->count+=sum;
        return sum;
    }
}
void find(ll index,node *now,int dig,ll &findnum)
{
    if(dig==0)
    {
        return;
    }
    if(index>now->next[0]->count)
    {
        findnum|=(1<<(dig-1));
        find(index-now->next[0]->count,now->next[1],dig-1,findnum);
    }
    else
    {
        find(index,now->next[0],dig-1,findnum);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        inserta(tmp,digit,&A);
    }
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        insertans(tmp,digit,&res,&A);
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;++i)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        if(x==0)
        {
            ll resnum;
            find(y,&res,digit,resnum);
        }
    }
    return 0;
}