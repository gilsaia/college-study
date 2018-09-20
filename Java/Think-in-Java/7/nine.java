class a{
    a(){
        System.out.println("a");
    }
}
class b{
    b(){
        System.out.println("b");
    }
}
class c{
    c(){
        System.out.println("c");
    }
}
class root{
    a aa=new a();
    b bb=new b();
    c cc=new c();
    root(){
        System.out.println("root");
    }
}
class nine extends root{
    nine(){
        System.out.println("main");
    }
    public static void main(String[] args) {
        nine t=new nine();
    }
}