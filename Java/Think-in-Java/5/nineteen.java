class nineteen
{
    public static void main(String[] args) {
        varargs("abc","de","fgh");
        String[] t=new String[3];
        for(int i=0;i<3;i++)
        {
            t[i]="bcd";
        }
        varargs(t);
    }
    static void varargs(String... args)
    {
        System.out.println("success!");
    }
}