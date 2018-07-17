#include<iostream>
#include"Sales_item.h"
int main()
{
//1.20
    Sales_item t;
    std::cin>>t;
    std::cout<<t;
//1.21
    Sales_item a,b;
    std::cout<<"Please input two Sales item"<<std::endl;
    std::cin>>a>>b;
    std::cout<<"The sum is "<<a+b<<std::endl;
//1.22
    Sales_item sum,temp;
    while(std::cin>>temp)
    {
        sum+=temp;
    }
    std::cout<<"The sum is "<<sum<<std::endl;
    return 0;
}