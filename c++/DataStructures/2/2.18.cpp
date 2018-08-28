double f(double x);
double find(double low,double high)
{
    bool tosave=(f(low)>=0);
    for(int i=0;i<100;i++)
    {
        double mid=(low+high)/2;
        if((f(mid)>=0)^tosave==0)
        {
            low=mid;
        }
        else
        {
            high=mid;
        }
    }
    return low;
}