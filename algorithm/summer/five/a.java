import java.util.*;
import java.math.BigInteger;

public class Main
{
    static BigInteger pow[][] = new BigInteger[100005][12];
    public static void main(String[]args)
    {

        for(int i = 1;i<=100000;i++)
        {
            pow[i][0] = BigInteger.ONE;
            for(int j = 1;j<=10;j++)
            {
                pow[i][j] = pow[i][j-1].multiply(BigInteger.valueOf((long)i));
            }
        }
        String INF = "1";
        for(int i  =1;i<=60;i++) INF = INF+"0";
        Scanner sc = new Scanner(System.in);
        int ca = sc.nextInt();

        while(ca-- != 0)
        {
            int n = sc.nextInt(),z = sc.nextInt();
            int X = 0,Y = 0;
            BigInteger ans = new BigInteger(INF);
            for(int i = 2;i<z;i++)
            {
                BigInteger num = pow[1][n].add(pow[i][n]).subtract(pow[z][n]);
                if(num.compareTo(BigInteger.ZERO) >= 0)
                {
                    if(num.compareTo(ans) == -1) {
                        ans = num;
                        X = 1;
                        Y = i;
                        //System.out.println(X+" "+Y+" "+num);
                    }
                    continue;
                }
                int l = 1,r = i-1;
                while(l < r)
                {
                    int mid = (l+r+1>> 1);
                    num = pow[mid][n].add(pow[i][n]).subtract(pow[z][n]);
                    if(num.compareTo(BigInteger.ZERO) == -1)
                    {
                        l = mid;
                    }
                    else r = mid-1;
                }
                num = pow[l][n].add(pow[i][n]).subtract(pow[z][n]);
                num = num.multiply(BigInteger.valueOf(-1l));

                if(num.compareTo(ans) == -1)
                {
                    ans = num;
                    X = l;
                    Y = i;

                }

                if(l < i-1)
                {
                    l++;
                    num = pow[l][n].add(pow[i][n]).subtract(pow[z][n]);
                    if(num.compareTo(ans) == -1)
                    {
                        ans = num;
                        X = l;
                        Y = i;
                    }
                }
                //System.out.println(X+" "+Y+" "+num);
            }
            System.out.printf("%d %d ",X,Y);
            System.out.println(ans);
        }
        sc.close();
    }
}