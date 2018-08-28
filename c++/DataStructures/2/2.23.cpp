long long pow(long long x,int n)
{
    long long ans=1;
    while(n!=0)
    {
        if(n&1)
        {
            ans*=x;
        }
        x*=x;
        n/=2;
    }
    return ans;
}