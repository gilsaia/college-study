#include<iostream>
using namespace std;
int main()
{
    int a1,a2,a3,a4,n;
    cin>>n>>a1>>a2>>a3>>a4;
    int num=0;
    for(int a=1;a<=n;a+=a1)
    {
        for(int b=1;b<=a;b+=a2)
        {
            for(int c=1;c<=b;c+=a3)
            {
                for(int d=1;d<=c;d+=a4)
                {
                    num++;
                }
            }
        }
    }
    cout<<num;
    return 0;
}