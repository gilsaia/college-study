 #include<iostream>
 int main()
 {
    int m,n;
    std::cout<<"Please input two numbers"<<std::endl;
    std::cin>>m>>n;
    if(m>n)
    {
        int temp=m;
        m=n;
        n=temp;
    }
    while(m<=n)
    {
        std::cout<<m++;
    }
    return 0;
 }