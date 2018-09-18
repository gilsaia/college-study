#include<iostream>
template <typename Object>
class list
{
    struct Node
    {
        Object data;
        Node *next;
        Node(const Object &x=Object{},Node *n=nullptr):data{x},next{n}{}
    }
    Node *head,*tail,*last;
    list()
    {
        head=new Node;
        tail=new Node;
        head->next=tail;
        last=head;
    }
    public:
    void insert(Object &x)
    {
        Node *tmp=new Node{x,tail};
        last->next=tmp;
        last=last->next;
    }
    void reverseout()
    {
        Node *check=tail,*cur=head;
        while(check!=head->next)
        {
            while(cur->next!=check)
            {
                cur=cur->next;
            }
            std::cout<<cut->data<<std::endl;
            check=cur;
            cur=head;
        }
    }
}