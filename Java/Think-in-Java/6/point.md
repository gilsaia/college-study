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