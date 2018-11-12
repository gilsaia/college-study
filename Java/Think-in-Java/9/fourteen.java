interface ONE{
    void one();
    void One();
}
interface TWO{
    void two();
    void Two();
}
interface THREE{
    void three();
    void Three();
}
interface SIX extends ONE,TWO,THREE{
    void six();
}
class four{
    four(){}
    public void FOUR(){}
}
class six extends four implements SIX{
    public void one(){}
    public void One(){}
    public void two(){}
    public void Two(){}
    public void three(){}
    public void Three(){}
    public void six(){}
}
public class fourteen{
    static void a(ONE A)
    {
        A.one();
    }
    public static void main(String[] args) {
        six t=new six();
        a(t);
    }
}