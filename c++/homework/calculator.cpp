#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<fstream>
#include<iostream>
#include<algorithm>
template <typename comparable>
struct link
{
    comparable coefficient,index;
    link *next;
    link(comparable coe=comparable{},comparable ind=comparable{},link *n=nullptr):coefficient(coe),index(ind),next(n){}
    bool operator<(const link &camp)
    {
        if(index==camp.index)
        {
            return coefficient<camp.coefficient;
        }
        return index<camp.index;
    }
};
template <typename comparable>
class calculator
{
    public:
    void print();
    calculator(link);
    calculator(link[]);
    calculator(comparable,comparable);
    private:
    link<comparable> *root;
};
#endif