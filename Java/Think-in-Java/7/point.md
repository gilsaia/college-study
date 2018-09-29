### 7.1

当希望类能够直接按照字符串被打印时，在类内加一个toString()方法即可直接在输出语句中使用
``` Java
class waterSource
{
    public String toString()
    {
        return "confirm";
    }
    public static void main(String[] args)
    {
        waterSource tmp=new waterSource();
        System.out.println(tmp);
    }
}
```
类中的基本类型都会被初始化，但对象引用会被初始化为null，当试图为它们调用任何方法都会得到异常，但是在不抛出异常的情况下可以打印一个null引用

对引用进行初始化大概有以下几个方法

* 在定义对象的地方
* 在类的构造器中
* 在要使用这些对象之前，这种方式被称为惰性初始化
* 实例初始化

### 7.2

当继承类时继承类在类名后加extends加类名实现

被继承的类一般情况下要加好访问权限修饰，因为若为不同包的继承则只能访问public，protected的成员

当重载方法中希望调用基类的方法时，可用super关键词，表示超类，可以此调用基类版本的方法

为保证对基类的正确初始化，在构造器中会调用基类构造器来执行初始化

对没有默认构造器的基类，必须显式调用基类的构造器
```Java
class Game{
    Game(int i){
        System.out.println("Game!!!!!!!!!!!");
    }
}
public class chess extends Game{
    chess(){
        super(11);
        System.out.println("CHESS!!!!!!!");
    }
    public static void main(String[] args)
    {
        chess x=new chess();
    }
}
```
### 7.3

所谓的代理在Java不直接支持，但通过ide可以实现

代理是与继承有所差别的，继承是一个新的类型完全包括了旧的类型与方法，而代理首先通过组合在新的类中创建旧类，然后重写对应的方法，只是调用旧类的方法
```Java
class SpaceShipControls{
    void up(int v){}
    void down(int v){}
    //...
}
public class SpaceShip{
    private SpaceShipControls controls=new SpaceShipControls();
    public void up(int v){
        controls.up(v);
    }
    public void down(int v){
        controls.down(v);
    }
    //...
}
```
### 7.4

一旦涉及到垃圾处理器，要小心，如果有必要自己进行清理的话，可以编写自己的清理方法，但不要使用finalize()

如果Java的基类拥有某个已被多次重载的方法名称，那么在导出类中重新定义该方法名称不会屏蔽其在基类的任何版本

用添加的@override注解可以进行覆写而非重载

### 7.5

组合技术通常用于想在新类中使用现有类的功能而非它的接口

一般来说嵌入的现有类对象应为private，但在现有类自身已经做好了隐藏具体实现，将其设为public有时是非常有用的

继承关系表明的是具有"is-a"，而组合表明的是"has-a"

### 7.6

protected关键字可以保证对继承此类的导出类和其他任何位于同一个包内的类来说是可以访问的

### 7.7

对于接受基类类型的方法，传递一个导出类也能够执行，这个过程被称为向上转型

### 7.8

对于基本类型，final会将其定为常量(类似const)，而对于对象引用使用final关键字，会使引用固定不变但对象自身可以被改变

既是static又是final的域只占据一段不能改变的存储空间

所谓的空白final即声明为final但并未给定初值的域，编译器确保空白final在使用前必须初始化，可以在定义处或构造器等用表达式对其赋值

可以在参数列表中将参数指明为final，这样非基本类型不能够更改引用的指向，基本类型不能更改值

使用final方法目前的主要目的是要锁定方法，以防任何继承类修改它的含义

类中所有的private方法都默认是final的,且任何导出类都不应考虑这部分

将类声明为final意味着不能被继承，内部的域可以根据个人意愿来选择是否为final，但内部的方法会被隐式指定为final

### 7.9

一般来说，类的代码在初次使用时才会加载，这通常是指加载发生于创建类的第一个对象时，但是当访问static域或方法时也会发生加载(类的构造器也是隐式的static方法)