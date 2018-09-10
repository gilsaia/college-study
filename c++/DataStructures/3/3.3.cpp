template <typename Iterator,typename Object>
Iterator find(Iterator start,Iterator end,const Object & x)
{
    for(;start!=end;start++)
    {
        if(*start==x)
        {
            return start;
        }
    }
    return end;
}