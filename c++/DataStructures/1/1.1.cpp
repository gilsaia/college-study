#include<iostream>
const int N=1e6;
int tosel[N];
void selection(int n)
{
    int k=n/2;
    for(int i=0;i<=k;i++)
    {
        for(int t=n;t>0;t--)
        {
            if(tosel[t]>tosel[t-1])
            {
                int temp=tosel[t];
                tosel[t]=tosel[t-1];
                tosel[t-1]=temp;
            }
        }
    }
    std::cout<<tosel[k-1];
}