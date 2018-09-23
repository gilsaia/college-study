template <typename Object>
class duque
{
    struct Node
    {
        Object save;
        Node *next;
        Node *prev;
        Node(const Object & d=Object{},Node *p=nullptr,Node *n=nullptr):save{d},next{n},prev{p}{}
    }
    deque():dataSize{0}
    {
        head=new Node;
        tail=new Node;
        head->next=tail;
        tail->prev=head;
    }
    public:
    void push(Object x)
    {
        Node *tmp=new Node{x,head};
        tmp->next=head->next;
        head->next=head->next->prev=tmp;
        ++dataSize;
        return;
    }
    Object pop()
    {
        if(dataSize>0)
        {
            Object tmp=head->next->save;
            Node *topop=head->next;
            head->next=topop->next;
            topop->next->prev=head;
            delete topop;
            --dataSize;
            return tmp;
        }
        else
        {
            return Object{};
        }
    }
    void inject(Object x)
    {
        tail->prev=tail->prev->next=new Node{x,tail->prev,tail};
        ++dataSize;
        return;
    }
    Object eject()
    {
        if(dataSize>0)
        {
            Object tmp=tail->prev->save;
            Node *topop=tail->prev;
            topop->prev->next=tail;
            tail->prev=topop->prev;
            delete topop;
            --dataSize;
            return tmp;
        }
        else
        {
            return Object{};
        }
    }
    private:
    int dataSize;
    Node *head;
    Node *tail;
};