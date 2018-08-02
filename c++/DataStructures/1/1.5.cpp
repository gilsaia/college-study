int number(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n&1==1)
    {
        return number(n/2)+1;
    }
    else
    {
        return number(n/2);
    }
}