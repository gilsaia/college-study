#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int aans,bans;
int main()
{
    int a[35],b[35],test[35];
    for(int i=0;i<35;++i)
    {
        a[i]=b[i]=test[i]=0;
    }
    fflush(stdout);
    int atest=0,btest=0,nowstate;
    cout<<"? "<<atest<<" "<<btest<<endl;
    cin>>nowstate;
    for(int i=29;i>=0;--i)
    {
        if(nowstate==0)
        {
            break;
        }
        fflush(stdout);
        cout<<"? "<<(atest+(1<<i))<<" "<<(btest+(1<<i))<<endl;
        int teststate;
        cin>>teststate;
        if(teststate==nowstate)
        {
            continue;
        }
        else
        {
            test[i]=1;
            if(nowstate==1)
            {
                atest+=(1<<i);
                a[i]=1;
                b[i]=0;
            }
            else if(nowstate==-1)
            {
                btest+=(1<<i);
                a[i]=0;
                b[i]=1;
            }
            fflush(stdout);
            cout<<"? "<<atest<<" "<<btest<<endl;
            cin>>nowstate;
        }
    }
    for(int i=29;i>=0;--i)
    {
        if(test[i]==1)
        {
            continue;
        }
        fflush(stdout);
        cout<<"? "<<(atest+(1<<i))<<" "<<btest<<endl;
        int cmp;
        cin>>cmp;
        if(cmp==1)
        {
            a[i]=b[i]=0;
        }
        else if(cmp==-1)
        {
            a[i]=b[i]=1;
        }
    }
    for(int i=0;i<30;++i)
    {
        aans+=(a[i]<<i);
        bans+=(b[i]<<i);
    }
    fflush(stdout);
    cout<<"! "<<aans<<" "<<bans<<endl;
    return 0;
}