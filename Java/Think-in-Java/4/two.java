import java.util.*;
public class two
{
    public static void main(String[] args) {
        int tmp=0;
        Random rand=new Random(47);
        for(int i=0;i<25;i++)
        {
            if(i==0)
            {
                tmp=rand.nextInt();
                System.out.println(tmp);
            }
            else
            {
                int cmp=rand.nextInt();
                if(tmp<cmp)
                {
                    System.out.println("<"+cmp);
                }
                else if(tmp>cmp)
                {
                    System.out.println(">"+cmp);
                }
                else
                {
                    System.out.println("="+cmp);
                }
                tmp=cmp;
            }
        }
    }
}