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
    link(comparable coe=comparable(),comparable ind=comparable(),link *n=nullptr):coefficient(coe),index(ind),next(n){}
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
    calculator(link<comparable>);
    calculator(link<comparable>[]);
    calculator(comparable,comparable);
    calculator operator-()
    {
        link<comparable> *cur=root;
        while(cur!=nullptr)
        {
            cur->coefficient=-cur->coefficient;
            cur=cur->next;
        }
        return dat;
    }
    calculator operator+(const calculator &rhs)
    {
        link<comparable> *torhs=rhs.root,*tolhs=root;
        link<comparable> *result,*cur;
        result=new link<comparable>;
        cur=result;
        while(!(torhs==nullptr&&tolhs==nullptr))
        {
            if(torhs==nullptr)
            {
                cur->index=tolhs->index;
                cur->coefficient=tolhs->coefficient;
                link<comparable> *tmp;
                tmp=new link<comparable>;
                cur->next=tmp;
                cur=tmp;
                tolhs=tolhs->next;
            }
            else if(tolhs==nullptr)
            {
                cur->index=torhs->index;
                cur->coefficient=torhs->coefficient;
                link<comparable> *tmp;
                tmp=new link<comparable>;
                cur->next=tmp;
                cur=tmp;
                torhs=torhs->next;
            }
            else
            {
                if(torhs->index>tolhs->index)
                {
                    cur->index=torhs->index;
                    cur->coefficient=torhs->coefficient;
                    link<comparable> *tmp;
                    tmp=new link<comparable>;
                    cur->next=tmp;
                    cur=tmp;
                    torhs=torhs->next;
                }
                else if(torhs->index<tolhs->index)
                {
                    cur->index=tolhs->index;
                    cur->coefficient=tolhs->coefficient;
                    link<comparable> *tmp;
                    tmp=new link<comparable>;
                    cur->next=tmp;
                    cur=tmp;
                    tolhs=tolhs->next;
                }
                else
                {
                    cur->index=tolhs->index;
                    cur->coefficient=tolhs->coefficient+torhs->coefficient;
                    link<comparable> *tmp;
                    tmp=new link<comparable>;
                    cur->next=tmp;
                    cur=tmp;
                    tolhs=tolhs->next;
                    torhs=torhs->next;
                }
            }
        }
        cur->coefficient=(comparable)0;
        cur->index=(comparable)0;
        cur->next=nullptr;
        calculator sum(*result);
        return sum;
    }
    private:
    link<comparable> *root;
};
#endif