### 3.1

每个using声明引入命名空间的一个成员

一般来说头文件不应包含using声明

### 3.2

对于string对象有以下几种初始化方式
```C++
string s1;//默认空串
string s2(s1);//为s1副本
//string s2=s1;与上同
string s3("value");//为字面值副本
//string s3="value";与上同
string s4(n,'c')//由连续n个c字符组成
```
当需要初始化的值只有一个时，拷贝初始化与直接初始化皆可，而多个值需要初始化时一般都为直接初始化，若非要使用拷贝初始化则要建立显示临时对象如`string s8=string(10,'c');`但这种形式并没有任何优势

当希望读取的字符串保留空白符时可用`getline(is,s)//is为输入流，s为字符串`这样会读取至第一次遇到换行符，读入换行符但不会保存换行符

string的size函数返回的是string::size_type类型的值，是无符号的数，当进行比较时若比较的数为负数则可能会出现问题，负数被转换成一个很大的正数

对string的相加可以有字面值，但一定要有一个string

对于字符串的处理，在cctype头文件中定义了一组标准库函数来处理这部分工作

| 名称 | 效果 |
| --- | ---- |
| isalnum(c) | c为字母或数字是为真 |
| isalpha(c) | c为字母时为真 |
| iscntrl(c) | c是控制字符时为真 |
| isdigit(c) | c是数字为真 |
| isgraph(c) | c不是空格但可打印是为真 |
| islower(c) | c是小写字母时为真 |
| isprint(c) | c是可打印字符时为真(即c是空格或有可视形式) |
| ispunct(c) | c是标点符号时为真 |
| isspace(c) | c是空白时为真(空格，横向制表符，纵向制表符，回车符，换行符) |
| isupper(c) | c是大写字母为真 |
| isxdigit(c) | c是十六进制数字为真 |
| tolower(c) | 若c为大写则输出小写否则不变 |
| toupper(c) | 若c为小写则输出大写否则不变 |

对于c语言的标准库头文件name.h，c++中头文件有对应的cname，在内容上是一样的，但是c++版本的定义的名字从属于命名空间std，而.h的则没有

如果要处理给定序列的每个元素，可以用范围for来进行
```C++
string str("some string");
for(auto c:str)
{
    cout<<c<<endl;
}
```
若要改变序列中的值，可以将上述的c变为引用

使用下标时要注意是否在合理范围内，否则会产生不可预知的结果