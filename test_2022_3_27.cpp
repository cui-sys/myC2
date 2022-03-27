// const 总结
#include <iostream>
//在 C 语言中 const 修饰全局变量 num 变量名只读 内存空间在文字常量区(只读)、不能通过 num 的地址 修改空间内容
// const 修饰局部变量 变量名只读 内存空间在栈区(可读可写)、可通过地址 间接修改空间内容
using namespace std;
#if 0

//
//extern const int date;// const 修饰的全局变量 默认是内部链接（只在当前源文件有效，不能直接用于其他源文件）
//extern const int date = 5000;//编译时重新定义
extern const int date;
void test()
{
    cout << "全局date = " << date <<endl;
}

//尽量 const 替换 #define
//#define 无类型 不可进行类型检查
// const 有作用域，而 #define 不重视作用域，默认定义处到文件结尾，如果作用到作用域下有效的常量，那么#define 就不能用
#define MAX 1024//预处理阶段报错的话直接报 1024 而不是MAX
const short my_max = 1024 ; //const 有类型，可进行编译器类型安全检查
void func(short i)
{
    cout<<"short 函数"<<endl;
}
void func(int i)
{
    cout<<"int 函数"<<endl;
}
void test()
{
    func(MAX);//int
    func(my_max);//short
}

void func(void)
{
    //作用范围 是当前复合语句
    const int num = 10;

    //作用范围 当前位置到文件结束
    #define NUM 10
}
void test()
{
//    cout<<"num = "<<num<<endl;//-err 不识别
    cout<<"NUM = "<<NUM<<endl;
}

// 宏常量不会有命名空间，但是 const 是可以有的
namespace myspace
{
    #define MY_A 100
    //MY_A 属于整个文件 不属于该命名空间
    const int my_a = 100;
}
void test()
{
    cout <<"myspace:my_a = "<<myspace::my_a<<endl;
    //cout <<"myspace:MY_A = "<<myspace::MY_A<<endl;//-err
    cout <<"MY_A = "<<MY_A<<endl;
}
#endif
//引用(reference)
void test()
{

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
