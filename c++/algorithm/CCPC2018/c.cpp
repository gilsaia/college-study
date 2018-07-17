#include<iostream>
using namespace std;
int zhuan[256];
int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int n,m;
        cin>>n>>m;
        char a[70],b[70],c[70];
        cin>>a>>b>>c;
        zhuan[b[0]]=a[0];
        int t=b[0];
        t++;
        while(t<='Z')
        {
            int temp=zhuan[t-1];
            temp++;
            if(temp>'Z')
            {
                temp=temp-('Z'-'A')-1;
            }
            zhuan[t]=temp;
            t++;
        }
        t=b[0];
        t--;
        while(t>='A')
        {
            int temp=zhuan[t+1];
            temp--;
            if(temp<'A')
            {
                temp=temp+('Z'-'A')+1;
            }
            zhuan[t]=temp;
            t--;
        }
        for(int j=0;j<m;j++)
        {
            c[j]=zhuan[c[j]];
        }
        cout<<"Case #"<<i<<": "<<c<<endl;
    }
    return 0;
}