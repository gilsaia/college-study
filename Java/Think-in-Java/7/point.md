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