#include<string>
#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int bit[1000020],n;
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int kmpnext[10020];
void getnext(string &ps)
{
    kmpnext[0]=-1;
    int j=0,k=-1;
    while(j<ps.length())
    {
        if(k==-1||ps[j]==ps[k])
        {
            if(ps[++j]==ps[++k])
            {
                kmpnext[j]=kmpnext[k];
            }
            else
            {
                kmpnext[j]=k;
            }
        }
        else
        {
            k=kmpnext[k];
        }
    }
}
void makenext(string &ps)
{
    int q,k;
    kmpnext[0]=0;
    ps=ps+'\0';
    for(q=1,k=0;q<=ps.length();++q)
    {
        while(k>0&&ps[q]!=ps[k])
        {
            k=kmpnext[k-1];
        }
        if(ps[q]==ps[k])
        {
            ++k;
        }
        kmpnext[q]=k;
    }
}
int main()
{
    int s,q,t;
    string root,tofind;
    cin>>s>>root>>t>>tofind>>q;
    n=s+1;
    makenext(tofind);
    int i=0,j=0;
    set<int> sequence;
    for(i=0,j=0;i<root.length();++i)
    {
        while(j>0&&tofind[j]!=root[i])
        {
            j=kmpnext[j-1];
        }
        if(tofind[j]==root[i])
        {
            ++j;
        }
        if(j==tofind.length())
        {
            j=kmpnext[j-1];
            sequence.insert(i+1);
            add(i+1,1);
        }
    }
    for(int i=0;i<q;++i)
    {
        char opera;
        cin>>opera;
        if(opera=='Q')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            int ans=sum(b)-sum(a);
            printf("%d\n",ans);
        }
        else if(opera=='C')
        {
            int num;
            scanf("%d",&num);
            num--;
            char tochange;
            cin>>tochange;
            root[num]=tochange;
            auto toi=sequence.lower_bound(num+1);
            while(*toi<=num+t)
            {
                add(*toi,-1);
                int toera=*toi;
                toi++;
                sequence.erase(toera);
            }
            int m=max(0,num-t+1),ne=0;
            for(;m<min(s,num+t);++m)
            {
                while(ne>0&&tofind[ne]!=root[m])
                {
                    ne=kmpnext[ne-1];
                }
                if(tofind[ne]==root[m])
                {
                    ++ne;
                }
                if(ne==tofind.length())
                {
                    ne=kmpnext[ne-1];
                    sequence.insert(m+1);
                    add(m+1,1);
                }
            }
        }
    }
    return 0;
}