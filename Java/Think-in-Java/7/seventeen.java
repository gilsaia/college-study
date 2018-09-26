class Amphibian{
    static void turn(Amphibian i)
    {
        System.out.println(i);
    }
    public String toString(){
        return "Amphibian";
    }
}
class seventeen extends Amphibian{
    public String toString(){
        return "Frog";
    }
    public static void main(String[] args) {
        seventeen now=new seventeen();
        turn(now);
    }
    static void turn(seventeen i)
    {
        System.out.println(i+"1");
    }
}