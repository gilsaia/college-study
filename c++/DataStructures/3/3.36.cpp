template <typename iterator>
void erase(iterator x)
{
    iterator tmp=x->next;
    x->data=x->next->data;
    x->next=x->next->next;
    delete tmp;
}