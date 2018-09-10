//单向链表
template <typename object>
class list
{
    private:
    struct node
    {
        object data;
        node *next;
        node(const object &d=object{},node *p=nullptr):data{d},next{p}{}
    };
    void swap(node *a,node *b);
    int size;
    node *head;
    node *tail;
};
template <typename object>
void list<object>::swap(node *a,node *b)
{
    if(b->next==a)
    {
        node *tmp=a;
        a=b;
        b=tmp;
    }
    node *tmp=head;
    while(tmp->next!=a)
    {
        tmp=tmp->next;
    }
    tmp->next=b;
    a->next=b->next;
    b->next=a;
    return;
}
//双向链表
template <typename object>
class List
{
    private:
    struct node
    {
        object data;
        node *next;
        node *prev;
        node(const object &d=object{},node *p=nullptr,node *n=nullptr):data{d},next{p},nect{n}{}
    };
    void swap(node *a,node *b);
    int size;
    node *head;
    node *tail;
};
template <typename object>
void List<object>::swap(node *a,node *b)
{
    if(b->next==a)
    {
        node *tmp=a;
        a=b;
        b=tmp;
    }
    node *pre=a->prev;
    pre->next=b;
    a->next=b->next;
    b->next=a;
    a->next->prev=a;
    a->prev=b;
    b->prev=pre;
    return;
}