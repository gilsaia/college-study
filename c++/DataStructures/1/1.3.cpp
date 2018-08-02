#include<iostream>
void printDigit(int n)
{
    std::cout<<n;
}
void printint(int n)
{
    if(n>=10)
    {
        printint(n/10);
    }
    printDigit(n%10);
}
void printdouble(double toprint)
{
    if(toprint<0)
    {
        std::cout<<"-";
        toprint*=-1;
    }
    int temp=toprint;
    toprint-=temp;
    printint(temp);
    if(toprint>0)
    {
        std::cout<<".";
        while(toprint>0)
        {
            toprint*=10;
            int t=toprint;
            printDigit(t);
            toprint-=t;
        }
    }

}