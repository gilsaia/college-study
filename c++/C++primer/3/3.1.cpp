#include<string>
#include<iostream>
using std::cin;
using std::cout;
using std::string;
struct Sales_data
{
    string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
};
int main()
{
    Sales_data total;
    int price;
    if(cin>>total.bookNo>>total.units_sold>>price)
    {
        total.revenue=total.units_sold*price;
        Sales_data trans;
        int price2;
        while(cin>>trans.bookNo>>trans.units_sold>>price2)
        {
            trans.revenue=trans.units_sold*price2;
            if(total.bookNo==trans.bookNo)
            {
                total.revenue+=trans.revenue;
            }
            else
            {
                cout<<total.bookNo<<" "<<total.revenue;
                total=trans;
            }
        }
        cout<<total.bookNo<<" "<<total.revenue;
    }
}