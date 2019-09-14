#ifndef sum
#define sum a+b
#endif
#ifdef sum
#define sum_2 a+b+b
#endif
//this is for test
int main()
{
    int a=1,b=1;
    int t=sum;
    int s=sum_2;
    return 0;
}