### 10.1

对外部类的非静态方法之外的任意位置创建某个内部类的对象，必须要按照 `OuterClassName.InnerClassName` 一样指明类型

### 10.2

生成一个内部类的对象时，此对象可以访问其外围对象的所有成员而不需任何特殊条件

### 10.3

需要生成对外部类对象的引用，可以用外部类对象的名字后紧跟圆点和this

在拥有外部类对象之前是不可能创建内部类对象的，但是如果创造的是嵌套类（静态内部类），则可以不需要外部类对象的引用

### 10.6

对于下列代码
```Java
public class Parvel7{
    public Contents contents(){
        return new Contents(){
            private int i=11;
            public int value(){return i;}
        };
    }
}
```
实际为下列形式的简化
```Java
public class Parcel7b{
    class MyContents implements Contents{
        private int i=11;
        public int value(){return i;}
    }
    public Contents contents(){return new MyContents();}
}
```
