import java.util.*;
import java.math.BigInteger;

public class Main
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        BigInteger x=sc.nextBigInteger(),y=sc.nextBigInteger(),z=sc.nextBigInteger();
        BigInteger ans=x.add(y).add(z);
        sc.close();
        System.out.println(ans);
    }
}