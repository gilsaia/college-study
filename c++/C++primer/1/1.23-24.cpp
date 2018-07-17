#include<iostream>
#include"Sales_item.h"
#include<string>
int main()
{
    int cnt=0;
    Sales_item temp,tem;
    if(std::cin>>temp)
    {
        cnt=1;
        while(std::cin>>tem)
        {
            if(temp.isbn==tem.isbn)
            {
                cnt++;
            }
            else
            {
                std::cout<<temp<<" occur "<<cnt<<" times"<<std::endl;
                temp=tem;
                cnt=1;
            }
        }
        std::cout<<temp<<" occurs "<<cnt<<" times"<<std::endl;
    }
    return 0;
}