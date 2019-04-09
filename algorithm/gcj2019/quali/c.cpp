#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;
struct upper
{
    int value,num;
};
bool cmp(upper a,upper b)
{
    return a.value<b.value;
}
bool isprime[10020];
int main()
{
    isprime[0]=isprime[1]=true;
    set<int> primetree;
    for(int i=2;i<=10000;++i)
    {
        if(!isprime[i])
        {
            primetree.insert(i);
            for(int j=i*2;j<=10000;j+=i)
            {
                isprime[j]=true;
            }
        }
    }
    int T;
    cin>>T;
    for(int m=1;m<=T;++m)
    {
        int N,L;
        cin>>N>>L;
        int mulres[120],tosort[120];
        for(int i=0;i<L;++i)
        {
            cin>>mulres[i];
        }
        multiset<int> nowfind;
        int lastnum=0;
        for(int i=0;i<L;++i)
        {
            for(auto t=primetree.begin();t!=primetree.end();++t)
            {
                if(mulres[i]%(*t)==0)
                {
                    int a=*t,b=mulres[i]/(*t);
                    if(i==0)
                    {
                        nowfind.insert(a);
                        nowfind.insert(b);
                        break;
                    }
                    if(i==1)
                    {
                        if(nowfind.find(a)==nowfind.end())
                        {
                            nowfind.erase(b);
                            tosort[lastnum++]=*nowfind.begin();
                            nowfind.clear();
                            nowfind.insert(a);
                            tosort[lastnum++]=b;
                            break;
                        }
                        else
                        {
                            nowfind.erase(nowfind.find(a));
                            tosort[lastnum++]=*nowfind.begin();
                            nowfind.clear();
                            nowfind.insert(b);
                            tosort[lastnum++]=a;
                            break;
                        }
                    }
                    if(nowfind.find(a)==nowfind.end())
                    {
                        nowfind.erase(b);
                        tosort[lastnum++]=b;
                        nowfind.insert(a);
                        break;
                    }
                    else
                    {
                        nowfind.erase(nowfind.find(a));
                        tosort[lastnum++]=a;
                        nowfind.insert(b);
                        break;
                    }
                }
            }
        }
        tosort[lastnum++]=*nowfind.begin();
        upper soo[120];
        for(int i=0;i<lastnum;++i)
        {
            soo[i].value=tosort[i];
            soo[i].num=i;
        }
        sort(soo,soo+lastnum,cmp);
        int lastchar=soo[0].value,nownum=0;
        char str[120];
        for(int i=0;i<lastnum;++i)
        {
            if(soo[i].value==lastchar)
            {
                str[soo[i].num]='A'+nownum;
            }
            else
            {
                lastchar=soo[i].value;
                ++nownum;
                str[soo[i].num]='A'+nownum;
            }
        }
        cout<<"Case #"<<m<<": ";
        for(int i=0;i<lastnum;++i)
        {
            cout<<str[i];
        }
        cout<<endl;
    }
    return 0;
}