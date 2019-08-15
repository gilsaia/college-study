import java.util.*;
import java.math.BigInteger;
import java.lang.*;
public class Main
{
    static BigInteger pow[]=new BigInteger[300];
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        pow[0]=BigInteger.ZERO;
        pow[1]=new BigInteger("3");
        BigInteger SIX=new BigInteger("6");
        BigInteger TWO=new BigInteger("2");
        for(int i=2;i<300;++i)
        {
            pow[i]=pow[i-1].multiply(SIX).subtract(pow[i-2]).add(TWO);
        }
        for(int i=0;i<T;++i)
        {
            BigInteger x=sc.nextBigInteger();
            int num=0;
            while(pow[num].compareTo(x)<0)
            {
                ++num;
            }
            System.out.println(pow[num]);
        }
        sc.close();
    }
}