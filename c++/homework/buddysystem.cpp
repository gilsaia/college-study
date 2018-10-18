#ifndef BUDDYSYSTEM_H
#define BUDDYSYSTEM_H
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
using ll=long long;
using std::pair;
using std::cout;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::vector;
struct node
{
    ll address,size;
    node *next;
    node(ll add=0,ll size=1024,node *n=nullptr):address(add),next(n)
    {
        ll modsize=1;
        while(modsize<size)
        {
            modsize<<=1;
        }
        size=modsize;
    }
    bool operator<(const node &rhs)
    {
        if(size==rhs.size)
        {
            return address<rhs.address;
        }
        return size>rhs.size;
    }
};
class buddysystem
{
    public:
    buddysystem()
    {
        tail=head=new node();
    }
    buddysystem(ll size)
    {
        tail=head=new node(0,size);
    }
    private:
    node *insert(ll address,ll size)
    {
        if(head!=nullptr)
        {
            node *ine=new node(address,size),*find=head;
            if(*ine<*head)
            {
                ine->next=head;
                head=ine;
                return head;
            }
            else
            {
                while(find->next!=nullptr&&(*(find->next)<*ine))
                {
                    find=find->next;
                }
                ine->next=find->next;
                find->next=ine;
                if(ine->next==nullptr)
                {
                    tail=ine;
                }
                return ine;
            }
        }
        else
        {
            head=tail=new node(address,size);
            return head;
        }
    }
    node *erase(ll address,ll size)
    {
        if(head!=nullptr)
        {
            if(head->address==address&&head->size==size)
            {
                node *oldnode=head;
                head=head->next;
                if(head==nullptr)
                {
                    tail=nullptr;
                }
                delete oldnode;
                return head;
            }
            else
            {
                node *find=head;
                while(find->next!=nullptr&&!(find->next->address==address&&find->next->size==size))
                {
                    find=find->next;
                }
                node *oldnode=find->next;
                if(oldnode==nullptr)
                {
                    return nullptr;
                }
                find->next=find->next->next;
                delete oldnode;
                if(find->next==nullptr)
                {
                    tail=find;
                }
                return find;
            }
        }
        else
        {
            return nullptr;
        }
    }
    node *head,*tail;
    vector<pair<ll,ll>> used;
};
#endif