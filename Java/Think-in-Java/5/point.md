### 5.2

重载依旧按照参数列表来分开，基本类型可以自动提升但不能自动窄化转换，除非强制变换类型否则会报错

### 5.3

默认构造函数仍然保持如果写入其他构造函数则不默认生成

### 5.4

当在方法内部调用同一个类的另一个方法，可以不必使用this

在一个构造器内调用另一个构造器时可用this调用但只可用一次且 **必须将构造器调用放在最起始处**

除构造器外，编译器禁止在其他任何地方调用构造器

### 5.5

Java中并没有类似析构函数的设计，垃圾回收机制与析构函数并不相同，在某些特殊的调用本地方法(例如C的malloc（）方法)，需要在方法中创建finalize()方法里调用本地方法(按照上例为C的free()方法)

终结函数可以用来验证对象的终结条件

一般来说总要调用基类的finalize()，所以在写的最后一般要加一句`super.finalize();`

### 5.6

方法中若有值为初始化会报错，类中数据成员若为基本类型则会有一个初始值，定义对象引用若不初始化则会有一个特殊值null

想为某个变量赋初值可直接在定义的地方赋值(**注意C++不能这样！**)

可以调用方法，包括无参或含参但是若含参一定要是初始化过的

### 5.7

变量初始化顺序在构造器初始化之前

静态对象只有在用到的时候才会被初始化，初始化顺序是先静态对象，而后非静态对象，静态对象只会被初始化一次

Java允许将多个静态初始化动作组织成一个特殊的“静态子句”，即类似
```Java
Class cups
{
    static cup cup1;
    static cup cup2;
    static
    {
        cup1=new cup(1);
        cup2=new cup(2);
    }
    //...
}
```
对于非静态成员，也有类似的被称作实例初始化的语法
```Java
class Mugs
{
    Mug mug1;
    Mug mug2;
    {
        mug1=new Mug(1);
        mug2=new Mug(2);
    }
    //...
}
```
他们执行在构造器之前，即第一次调用相关类或静态成员时

### 5.8

对于数组的初始化，既可以如C++一般`int a[]`，也可以像`int[] a`，后者直观上的意思表明类型是“一个int数组”

编译器不允许指定数组的大小

创建数组可以有一种特殊的表达式，以花括号括起来的值，此时存储空间的分配由编译器负责
```Java
int[] a1={1,2,3,4,5};
```
注意以上的标识符皆为 **引用**

超出边界时Java与C++不同，Java会直接报错，这导致每次访问数组时都会进行安全检查

数组都有一个固有成员，**length**

不同于基本类型，其他类型若创建了引用数组即使用 **new**创建数组后也只是引用数组，直到通过创建新的对象并把对象赋值给引用初始化进程才算结束，如果忘记创建对象并且试图使用数组中的空引用，就会在运行时产生异常

也可以用花括号括起来的列表初始化对象数组，有两种方式
```Java
Integer[] a={new Integer(1),new Integer(2),3,};
//最后一个初始化用到了自动包装机制
//最后一个逗号是可选的
//这种方式只能用于数组被定义之处
Integer[] b=new Integer[]{new Integer(1),new Integer(2),3,};
//这种方式可以在任意地方使用，甚至是方法调用的内部
```

有可变参数列表可以自动填充数组，当传递数组时则不会进行任何转换，可以使用任何类型的可变参数列表，包括基本类型，可变参数列表不依赖于自动包装机制
```Java
class newvarargs
{
    static void printArray(Object... args)
    {
        for(Object obj:args)
        {
            System.out.print(obj+' ');
        }
        System.out.println();
    }
    //...
}
```
当有多个重载函数使用可变参数列表时，对于无参的调用可能产生错误，所以尽量只在重载方法的一个版本使用可变参数列表或尽量不使用，当无法避免冲突时可在每个重载方法前放一个非可变参数

### 5.9

对于枚举类型enum，可以直接变为string打印，同时也自带ordinal()方法用来表示某个特定enum常量的声明顺序，以及static values()声明方法，用来按照常量的声明顺序产生由常量值构成的数组
```Java
public enum Spcic
{
    NOT,MILD,MEDIUM,HOT,FLAMING
}
public class totest
{
    public static void main(String[] args)
    {
        for(Spcic s:Spcic.values())
        {
            System.out.println(s+".ordinal"+s.ordinal());
        }//序号从0开始
    }
}
```
enum可以和switch语句联合使用
```Java
public static void main(String[] args)
{
    Spcic de;
    //...
    switch(de)
    {
        case NOT:System.out.println("00");
        break;
        case MILD:;//...
        //...
        default:;
    }
}
```