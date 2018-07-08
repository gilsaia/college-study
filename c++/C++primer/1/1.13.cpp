#include<iostream>
int main()
{
//1.13(1.9)
    int sum=0;
    for(int i=50;i<=100;i++)
    {
        sum+=i;
    }
//1.13(1.10)
    for(int i=10;i>=0;i--)
    {
        std::cout<<i;
    }
//1.13(1.11)
    int m,n;
    std::cout<<"Please input two numbers"<<std::endl;
    for(int i=m;i<=n;i++)
    {
        std::cout<<i;
    }
    return 0;
}