template <typename iterator>
bool findloop(iterator cur)
{
    iterator tmp=cur;
    bool pan=0;
    while(tmp->next!=nullptr)
    {
        if(tmp->next==cur)
        {
            return 1;
        }
        tmp=tmp->next;
    }
    return 0;
}