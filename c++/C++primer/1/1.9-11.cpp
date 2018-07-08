#include<iostream>
int main()
{
//1.9
    int i=50,sum=0;
    while(i<=100)
    {
        sum+=i++;
    }
//1.10
    i=10;
    while(i>=0)
    {
        std::cout<<i--;
    }
//1.11
    int m,n;
    std::cout<<"Please input two numbers"<<std::endl;
    std::cin>>m>>n;
    while(m<=n)
    {
        std::cout<<m++;
    }
    return 0;
}