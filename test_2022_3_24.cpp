#include <iostream>
//使用标准的命名空间
// std 中的所有成员名都可以直接使用
//cout endl cin 都是命名空间 std 的成员
//using namespace std;
using namespace std;
#if 0
//C++ 对语法的增强
// c 语言代码：
// int a = 10;//赋值，当做定义
// int a;//同名且没有赋值，当做声明（如果没有上一个同名定义，此行代码将变成定义。）
// c 语言中可以将函数形参定义成无类型，这时形参可以是任何类型，在 C++ 中必须有类型定义
// void fun1(i)
// {
//      printf("i = %d\n",i);
// }
// void fun2(i)
// {
//      printf("i = %s\n",i);
// }
// int main(){
//      printf("a:%d\n",a);
//      fun1(123);
//      fun2("string");
//      return EXIT_SUCCESS;
// }
//此代码在 C++ 下编译失败，在 C 下编译通过。
//在 C++ 不同类型的变量一般是不能直接复制的，需要相映的强转。C 是可以的
// typedef enum COLR{ GREEN, RED, YELLOW } color;
// int main()
// {
//      color mycolor = GREEN;
//      mycolor = 10;
//      printf("mycolor:%d\n", mycolor);
//      char* p = macolor(10);
//      return EXIT_SUCCESS;
// }
//以上 C 代码 C编译器编译可通过，C++ 编译器无法编译通过。
//
//C++对结构体的增强
// c 中定义结构体变量要加上 struct 关键字，c++ 不需要。
// c 中的结构体只能定义成员变量，不能定义成员函数。
// c++ 既可以定义成员变量，也可以定义成员函数。
// struct stu
// {
//     int num;
//     char name[32];
//     void func();//ree - c 语言不允许在结构体中定义成员函数
// };
// void test1()
// {
//      //c 语言必须加关键字 struct
//      struct stu lucy = { 100，"lucy" };
// }
#endif
struct stu
 {
    int num;
    char name[32];
    void func();// c++ 允许在结构体中定义成员函数
 };
void test1()
{
    //c++ 语言不用加 struct
    stu lucy = { 100, "lucy" };
    //调用成员函数
    lucy.func();
}

enum COLR{ GREEN, RED, YELLOW };
int main(int argc, char *argv[])
{
//    std::cout << "hello world" << std::endl;
//    cout << "hello world" << endl;
    COLR mycolor = GREEN;
//    mycolor = 10;//ree
    test1();
    return 0;
}
