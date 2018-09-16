#ifndef LIST_H
#define LIST_H
#include<iostream>
using std::cout;
using std::endl;
template <typename Object>
class chain
{
    struct node
    {
        Object value;
        node *next;
    };
    node *head;
    int size;
    public:
    chain():size{0}{head=new node;head->next=head;head->value=0;}
    chain(Object s):size{1}{head=new node;head->next=head;head->value=s;}
    ~chain()
    {
        node *tmp=head->next,*del=tmp;
        while(tmp!=head)
        {
            tmp=del->next;
            delete del;
            del=tmp;
        }
        delete head;
    }
    const int size() const
    {
        return size;
    }
    void print()
    {
        node *tmp=head;
        for(int i=0;i<size;i++)
        {
            cout<<tmp->value<<endl;
            tmp=tmp->next;
        }
    }
    bool check(Object x)
    {
        node *tmp=head;
        for(int i=0;i<size;i++)
        {
            if(tmp->value==x)
            {
                return true;
            }
            tmp=tmp->next;
        }
        return false;
    }
    void insert(Object x)
    {
        if(size==0)
        {
            head->value=x;
            return;
        }
        node *tmp=head;
        if(tmp->value==x)
        {
            return;
        }
        for(int i=0;i<size-1;i++)
        {
            if(tmp->next->value==x)
            {
                return;
            }
            if(tmp->next->value>x)
            {
                break;
            }
            tmp=tmp->next;
        }
        node *toin=new node;
        toin->value=x;
        toin->next=tmp->next;
        tmp->next=toin;
        ++size;
    }
    void erase(Object x)
    {
        if(size==0)
        {
            return;
        }
        else if(size==1&&head->value==x)
        {
            --size;
            return;
        }
        node *tmp=head;
        for(int i=0;i<size-1;i++)
        {
            if(tmp->next==x)
            {
                node *toera=tmp->next;
                tmp->next=toera->next;
                delete toera;
                --size;
                return;
            }
        }
    }
};
#endif