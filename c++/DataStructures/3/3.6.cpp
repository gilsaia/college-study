int Josephus(const int n,const int m)
{
    struct chain
    {
        int num;
        chain *next;
    };
    chain *loop,*head;
    loop=new chain;
    head=loop;
    for(int i=0;i<n-1;i++)
    {
        loop->num=i+1;
        chain *tmp=new chain;
        loop->next=tmp;
        loop=tmp;
    }
    loop->num=n;
    loop->next=head;
    int size=n;
    chain *cur=head;
    while(size>1)
    {
        int tosub=m%size;
        while(tosub>1)
        {
            cur=cur->next;
            tosub--;
        }
        chain *tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        size--;
    }
    int t=cur->num;
    delete cur;
    return t;
}