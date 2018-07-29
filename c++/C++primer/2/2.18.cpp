int main()
{
    int a=1,b=2;
    int *pa=&a;
    pa=&b;
    *pa=a;
    return 0;
}