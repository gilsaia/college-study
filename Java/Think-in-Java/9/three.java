abstract class basic
{
    public abstract void print();
    basic(){print();}
}
class then extends basic
{
    @Override
    public void print()
    {
        System.out.println(i);
    }
    private int i=15;
}
public class three
{
    public static void main(String[] args) {
        then c=new then();
        c.print();
    }
}