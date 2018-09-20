class a{
    a(int i){
        System.out.println("a"+i);
    }
}
class b{
    b(int i){
        System.out.println("b"+i);
    }
}
class c{
    c(int i){
        System.out.println("c"+i);
    }
}
class root{
    a aa=new a(1);
    b bb=new b(2);
    c cc=new c(3);
    root(int i){
        System.out.println("root"+i);
    }
}
class ten extends root{
    ten(int i){
        super(i);
        System.out.println("main"+i);
    }
    public static void main(String[] args) {
        ten t=new ten(123);
    }
}