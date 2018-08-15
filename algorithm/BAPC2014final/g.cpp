#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    double ans[12];
    while(n--)
    {
        double a,b,c;
        int num;
        cin>>num;
        for(int i=0;i<num;i++)
        {
            cin>>a>>b>>c;
            double temp=b/(2*a);
            ans[i]=-1*a*temp*temp+b*temp+c;
        }
        int out=-1;
        double dat=-1000;
        for(int i=0;i<num;i++)
        {
            if(ans[i]>dat)
            {
                out=i;
                dat=ans[i];
            }
        }
        printf("%d\n",out+1);
    }
    return 0;
}