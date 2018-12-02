import outer.inner;

class outer{
    class inner{
        int t;
    }
    public inner toretu()
    {
        return new inner();
    }
}
class one{
    public static void main(String[] args) {
        outer a=new outer();
        outer.inner s=a.toretu();
    }
}