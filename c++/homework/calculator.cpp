#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using std::vector;
using std::sort;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::pair;
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
    calculator()
    {
        root->coefficient=(comparable)0;
        root->index=(comparable)0;
        root->next=nullptr;
    }
    calculator(vector<link<comparable>> organ)
    {
        
    }
    calculator(link<comparable>*);
    ~calculator()
    {
        link *theold=root,*todel=root->next;
        while(todel!=nullptr)
        {
            delete theold;
            theold=todel;
            todel=todel->next;
        }
    }
    calculator operator-()
    {
        link<comparable> *cur=root;
        while(cur!=nullptr)
        {
            cur->coefficient=-cur->coefficient;
            cur=cur->next;
        }
        return *this;
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
                if(cur->coefficient!=(comparable)0&&cur->index!=(comparable)0)
                {
                    link<comparable> *tmp;
                    tmp=new link<comparable>;
                    cur->next=tmp;
                    cur=tmp;
                    tolhs=tolhs->next;
                }
            }
            else if(tolhs==nullptr)
            {
                cur->index=torhs->index;
                cur->coefficient=torhs->coefficient;
                if(cur->coefficient!=(comparable)0&&cur->index!=(comparable)0)
                {
                    link<comparable> *tmp;
                    tmp=new link<comparable>;
                    cur->next=tmp;
                    cur=tmp;
                    torhs=torhs->next;
                }
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
                    if(cur->coefficient!=(comparable)0&&cur->index!=(comparable)0)
                    {
                        link<comparable> *tmp;
                        tmp=new link<comparable>;
                        cur->next=tmp;
                        cur=tmp;
                        tolhs=tolhs->next;
                        torhs=torhs->next;
                    }
                }
            }
        }
        cur->next=nullptr;
        return calculator(result);
    }
    calculator operator-(const calculator &rhs)
    {
        return *this+(-rhs);
    }
    calculator operator*(const calculator &rhs)
    {
        link<comparable> *tolhs=root,*torhs=rhs.root,*temp,*tocreate;
        calculator result;
        while(tolhs->next!=nullptr)
        {
            temp=new link<comparable>;
            link<comparable> *calrhs=torhs,*tmpsave=temp;
            while(calrhs->next!=nullptr)
            {
                temp->coefficient=tolhs->coefficient*calrhs->coefficient;
                temp->index=tolhs->index+calrhs->index;
                tocreate=new link<comparable>;
                temp->next=tocreate;
                temp=tocreate;
                calrhs=calrhs->next;
            }
            temp->coefficient=(comparable)0;
            temp->index=(comparable)0;
            temp->next=nullptr;
            calculator toadd(tmpsave);
            result=result+toadd;
            tolhs=tolhs->next;
        }
        return result;
    }
    private:
    link<comparable> *root;
};
#endif