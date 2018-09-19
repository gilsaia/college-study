class basic{
    basic(int i){
        System.out.println("Basic!"+i);
    }
}
public class eight extends basic{
    eight(){
        super(0);
    }
    eight(int i){
        super(i);
    }
    public static void main(String[] args) {
        eight a=new eight(1);
        eight b=new eight();
    }
}