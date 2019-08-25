import java.lang.*;
import java.math.BigInteger;
import java.util.Scanner;
public class Main{
    static BigInteger a[]=new BigInteger[240];
    static BigInteger p[]=new BigInteger[240];
    static BigInteger TWO=new BigInteger("2");
    static BigInteger TRI=new BigInteger("3");
    public static void main(String[] args) {
        p[0]=BigInteger.ONE;
        for(int i=1;i<210;++i)
        {
            p[i]=p[i-1].multiply(TWO);
        }
        a[0]=a[1]=BigInteger.ZERO;
        for(int i=2;i<210;++i)
        {
            a[i]=a[i-1].multiply(TRI).add(p[i-1].multiply(p[i-1].subtract(BigInteger.ONE)).divide(TWO));
        }
        Scanner sc=new Scanner(System.in);
        BigInteger n;
        while(sc.hasNext())
        {
            n=sc.nextBigInteger();
            System.out.println(cal(n.add(BigInteger.ONE)));
        }
    }
    public static BigInteger cal(BigInteger n)
    {
        int x=0;
        for(int i=0;i<210;++i)
        {
            if(n.compareTo(p[i])<0)
            {
                x=i-1;
                break;
            }
        }
        BigInteger left=n.subtract(p[x]);
        if(left.compareTo(BigInteger.ZERO)==0)
        {
            return a[x];
        }
        BigInteger res=left.multiply(p[x].add(p[x]).subtract(BigInteger.ONE).subtract(left)).divide(TWO);
        return res.add(a[x]).add(cal(left).multiply(TWO));
    }
}