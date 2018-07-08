#include<iostream>
int main()
{
    std::cout<<"/*";
    std::cout<<"*/";
    std::cout<</*"*/"*/";
    std::cout<</*"*/"/*"/*"*/;
}
//注释时若有注释号在引号外则会寻找最近的注释结束符，其他情况下引号内会被认为是字符串而不作处理