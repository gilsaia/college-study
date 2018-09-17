## 6

访问权限控制的等级，从最大到最小依次为：public,protected,包访问权限（无关键词），private

### 6.1

在直接使用一个包时，是需要用全名来指定
```Java
public class qual{
    public static void main(String[] args){
        java.util.ArrayList list=new java.util.ArrayList();
    }
}
```
可以用`import java.util.ArrayList`代替以在代码中直接使用ArrayList

在编写一个Java源代码文件时，此文件通常被称作编译单元，单元内只能有一个public类，若有的话名称须与文件名称相同，在编译单元中的其他的类，在包之外的世界是无法看到的，因为它们不是public类

类库是一组类文件，当希望这些构件（每一个都有自己独立的.java和.class文件）同属于同一个群组，可以使用关键字package

如果使用，则必须是文件中除注释外的第一句代码 `package access;//access为类库名`，说明当前的public类在access名称下，想要使用必须指定全名或与import结合使用，多层关系可以`package access.mypackage;`类似关系

包的整个名称都为小写，一般为了创建自己的包可将域名反序

在有冲突时，完全写出一个类的顺序可避免冲突

Java没有C的条件编译功能，为了实现调试，可以创建不同的包，除了debug部分其他皆相同，最后通过修改导入的包来改变调试版到发布版的结果

### 6.2

如果不提供任何访问权限修饰词，则意味着它是“包访问权限”

包访问权限意味着当前包的所有其他类对那个成员都有访问权限，但对于包之外的其他类，这个成员是private，经由包访问权限，处于同一个编译单元的所有类彼此都是自动可访问的

取得对某成员的访问权限有以下几种

 * 使该成员成为public，因此无论是谁都可以访问该成员
 * 通过不加访问权限修饰词并将其他类放置于同一个包内的方式给成员赋予包访问权限
 * 通过继承而来的类可以访问public和protected成员
 * 通过Java提供的访问器和变异器方法

对于处于相同目录下且未给自己设定任何包名称，Java将自动把这些文件看作隶属于该目录的默认包中，于是为该目录中所有其他的文件都提供了包访问权限

使用类的客户端成员是无法访问包访问权限的成员的，只有声明为public才能被客户端程序员使用

protected也提供包访问权限

### 6.4

* 每个编译单元只能有一个public类，如果含有一个以上的public类编译器会报错
* public类与该编译单元的文件名必须完全匹配，包括大小写
* 但一个编译单元不含public是允许的

除了内部类外，类不可以是private或protected的

如果不希望其他人对该类有访问权限，可以把所有的构造器都指定为private，但该类的static成员内部可以创建
```Java
class Soup1{
    private Soup1(){}
    public static Soup1 makeSoup(){
        return new Soup1();
    }
}
class Soup2{
    private Soup2(){}
    private static Soup2 ps1=new Soup2();
    public static Soup2 access(){
        return ps1;
    }
    public void f(){}
}
public class Lunch{
    void testprivate(){
        //! Soup1 soup=new Soup1();
    }
    void testStatic(){
        Soup1 soup=Soup1.makeSoup();
    }
    void testsing(){
        Soup2.access().f();
    }
}
```
上面的Soup2用到了所谓的设计模式，这个设计模式被称为singleton(单例)