class A
{
    A(){System.out.println("A");}
}
class B
{
    B(){System.out.println("B");}
}
class five extends A
{
    B b=new B();
    public static void main(String[] args) {
        five c=new five();
    }
}