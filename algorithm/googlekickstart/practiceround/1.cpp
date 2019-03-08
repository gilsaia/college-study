#include<iostream>
#include<string>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;++i)
    {
        int A,B;
        cin>>A>>B;
        int n;
        cin>>n;
        while(true)
        {
            int mid=(A+B)/2+1;
            cout<<mid;
            string con;
            cin>>con;
            if(con=="CORRECT")
            {
                break;
            }
            if(con=="TOO_BIG")
            {
                B=mid-1;
            }
            else if(con=="TOO_SMALL")
            {
                A=mid;
            }
        }
    }
    return 0;
}