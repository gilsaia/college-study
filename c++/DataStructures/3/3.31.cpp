template <typename Object>
class Stack
{
    struct Node
    {
        Object data;
        Node *next;
        Node(const Object &x=Object(),Node *n=nullptr):data(x),next(n){}
    };
    Node *head;
    int size;
    public:
    Stack():size(0)
    {
        head=new Node;
    }
    void push(Object &x)
    {
        Node *tmp=new Node(x,head);
        ++size;
        head=tmp;
    }
    Object & top() const
    {
        return head->data;
    }
    void pop() const
    {
        if(size>0)
        {
            Node *topop=head;
            head=head->next;
            delete topop;
            --size;
            return;
        }
    }
};