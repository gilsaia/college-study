#include<iostream>
#include<algorithm>
using namespace std;
int prime[10]={2,3,5,7,11,13,17};
void makeeql(int &x,int &y,int mula,int mulb)
{
    while(x!=y)
    {
        if(x<y)
        {
            if((y-x)>=mula)
            {
                x+=(y-x)/mula*mula;
            }
            else
            {
                x+=mula;
            }
        }
        else
        {
            if((x-y)>=mulb)
            {
                y+=(x-y)/mulb*mulb;
            }
            else
            {
                y+=mulb;
            }
        }
    }
}
int main()
{
    int T,N,M;
    cin>>T>>N>>M;
    for(int m=1;m<=T;++m)
    {
        int ans[10];
        for(int i=0;i<7;++i)
        {
            ans[i]=0;
            cout<<prime[i];
            for(int j=0;j<17;++j)
            {
                cout<<" "<<prime[i];
            }
            cout<<endl;
            for(int j=0;j<18;++j)
            {
                int tmp;
                cin>>tmp;
                ans[i]+=tmp;
            }
        }
        int pos=2,mula=2,mulb=3,tmpx=ans[0],tmpy=ans[1];
        while(pos<7)
        {
            makeeql(tmpx,tmpy,mula,mulb);
            tmpy=ans[pos];
            mula*=mulb;
            mulb=prime[pos];
            ++pos;
        }
        cout<<tmpx<<endl;
        int pan;
        cin>>pan;
    }
    return 0;
}