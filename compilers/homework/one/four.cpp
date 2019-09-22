int main()
{
    long long a=0,b=1,c;
    #pragma omp parallel
    for(int i=0;i<100000000;++i)
    {
        c=a+b;
    }
    return 0;
}