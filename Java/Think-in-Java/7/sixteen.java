class Amphibian{
    static void turn(Amphibian i)
    {
        System.out.println(i);
    }
    public String toString(){
        return "Amphibian";
    }
}
class sixteen extends Amphibian{
    public String toString(){
        return "Frog";
    }
    public static void main(String[] args) {
        sixteen now=new sixteen();
        Amphibian.turn(now);
    }
}