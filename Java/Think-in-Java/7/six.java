class Game{
    Game(int i){
        System.out.println("Game!!!!!!!!!!!");
    }
}
public class six extends Game{
    six(){
        super(11);
        System.out.println("six!!!!!!!");
    }
    public static void main(String[] args)
    {
        six x=new six();
    }
}