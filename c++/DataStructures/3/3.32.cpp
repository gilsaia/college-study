template <typename Object>
class Queue
{
    struct Node
    {
        Object data;
        Node *next;
        Node(const Object &x=Object(),Node *n=nullptr):data(x),next(n){}
    };
    Node *top,*last;
    int size;
    public:
    Queue():size(0),top(nullptr),last(nullptr){}
    Queue(const Object &x):size(1)
    {
        top=new Node(x);
        last=top;
    }
    void push(Object &x)
    {
        if(top!=nullptr)
        {
            Node *tmp=new Node(x);
            top->next=tmp;
            top=tmp;
            ++size;
        }
        else
        {
            top=new Node(x);
            last=top;
            ++size;
        }
    }
    Object top()
    {
        if(size)
        {
            return last->data;
        }
    }
    void pop()
    {
        if(size)
        {
            Node *tmp=last;
            last=last->next;
            delete tmp;
        }
    }
};