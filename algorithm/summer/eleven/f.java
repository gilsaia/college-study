import java.util.*;
import java.math.BigInteger;
import java.lang.*;
public class Main
{
    static BigInteger pow[]=new BigInteger[240];
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        pow[0]=BigInteger.ONE;
        BigInteger TWO=new BigInteger("2");
        for(int i=1;i<210;++i)
        {
            pow[i]=pow[i-1].multiply(TWO);
        }
        for(int i=0;i<T;++i)
        {
            BigInteger x=sc.nextBigInteger();
            int num=0;
            while(pow[num].compareTo(x)<=0)
            {
                ++num;
            }
            --num;
            System.out.println(pow[num]);
        }
        sc.close();
    }
}