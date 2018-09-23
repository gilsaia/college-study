class threeoverride{
    threeoverride(){}
    void prr(int i)
    {
        System.out.println("int");
    }
    void prr()
    {
        System.out.println("void");
    }
    void prr(double i)
    {
        System.out.println("double");
    }
}
class thirteen extends threeoverride{
    void prr (char t)
    {
        System.out.println("char");
    }
    public static void main(String[] args) {
        thirteen tmp=new thirteen();
        tmp.prr(1);
        tmp.prr(1.2);
        tmp.prr();
        tmp.prr('c');
    }
}