### 8.2

将一个方法调用同一个方法主体关联起来称作绑定，在程序执行前进行绑定称作前期绑定，c语言唯一的方式就是前期绑定

而后期绑定（也称动态绑定或运行时绑定）能够在运行时判断对象的类型，Java中除了static方法和final方法之外其他所有方法都是后期绑定，在Java中后期绑定会自动发生，而将方法声明为final方法除了防止其他人覆盖该方法以外，能够“关闭”动态绑定，或者说告诉编译器不需要对其动态绑定，**但大多数情况下不应为了提高性能而使用而应出于设计来决定**

只有非private方法才可以被覆盖

如果直接访问某个域，这个访问就将在编译器进行解析，若某个方法是静态的，它的行为就不具有多态性

### 8.3

对复杂对象调用构造器遵循
1.迭代调用基类构造器
2.按声明顺序调用成员的初始化方法
3.调用导出类构造器的主体

销毁的顺序应该和初始化顺序相反

若有共享的需要清理的对象，要谨慎地使用引用计数并根据情况判断能否实现良好效果

在调用构造器前实际会将储存空间初始化为二进制的零，对引用则为null

### 8.5

一般来说设计结构时首先选择“组合”，因为它可以动态选择类型

Java对所有的类型转换都会进行检查，被称作“运行时类型识别”（RTTI）