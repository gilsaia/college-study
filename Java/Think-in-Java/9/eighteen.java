import java.util.*;
interface Cycle{
    boolean ride();
}
interface CycleFactory{
    Cycle getCycle();
}
class Unicycle implements Cycle{
    public boolean ride(){
        System.out.print("Unicycle");
        return true;
    }
}
class UnicycleFactory implements CycleFactory{
    public Cycle getCycle(){
        return new Unicycle();
    }
}
class Bicycle implements Cycle{
    public boolean ride(){
        System.out.print("Bicycle");
        return true;
    }
}
class BicycleFactory implements CycleFactory{
    public Cycle getCycle(){
        return new Bicycle();
    }
}
class eighteen{
    public static void play(CycleFactory factory){
        Cycle s=factory.getCycle();
        s.ride();
    }
    public static void main(String[] args) {
        play(new UnicycleFactory());
        play(new BicycleFactory());
    }
}