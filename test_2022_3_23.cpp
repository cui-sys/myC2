#include <iostream>

using namespace std;
#if 0
//无名命名空间，只能在本文件使用；相当于给这个标识符加上了 static ,使得其可以作为内部链接
//namespace {
//    int a=10;
//}
//无名的命名空间可直接访问；无名命名空间尽量少用
//void test1(){
//    cout<<"a:"<<a<<endl;
//}

//命名空间别名
namespace veryLongName {
     int a = 10;
     void func(){
         cout<<"hello namespace"<<endl;
     }
}
void test2(){
   namespace shorName = veryLongName;
   shorName::func();
   veryLongName::func();
}

//using 声明 - using 声明可以使得指定的标识符可用 - 简化了对命名空间的访问 - 一般不会使用 - 不安全
//容易冲突：1、与无名命名空间成员变量冲突      2、与局部变量冲突
namespace veryLongName2{
    int a=100;
    void fund(){
        cout<<"hello namespace2"<<endl;
    }
}
void test3(){
    int b = 1000;
    int a = 200;
    //从当前位置使用 veryLongName2 命名空间；
    using namespace veryLongName2;
    //下方出现的变量先从 veryLongName2 名空间中找，找不到再从其他路径找，找不到将会报错；
     cout<<"a="<<a<<endl;//访问局部变量 - 不会报错
     cout<<"a:"<< veryLongName2::a<<endl;//最安全
    fund();
}

//using 指明具体的命名空间 成员
 int a = 15;//局部变量设置成全局变量可以使用 - 这种的命名空间一般也不会使用 - 不安全
void test4(){

    using  veryLongName2::a;//这样容易和其他局部变量冲突，会报错
    cout<<"a="<<a<<endl;
    cout<<"全局变量 a="<<::a<<endl;//全局变量默认有(::)修饰访问
    //但是fund使用的时候，必须加作用域 - 指明哪个只能使用哪个,其他成员依旧要添加作用域来使用
    veryLongName2::fund();
}

//函数重载 - 一个函数名代表三个功能
//C语言中 函数名 代表是函数的入口地址
//C++ 中 函数名+参数 组合代表势函数的入口
namespace A {
    void func(){ cout << "无参" <<endl; }
    void func(int a){ cout << "1个参数" <<endl; }
    void func(int a,int b){cout << "两个参数" <<endl; }
}

void test5(){
    //using指明 使用 A 中的 func  会对 A 中所有的 func 起作用
//    using A::func;
//    func();
//    func(10);
//    func(10,20);
    A::func();
    A::func(10);
    A:: func(10,20);
}
void test6(){
    //using指明 使用 A 中的 func  会对 A 中所有的 func 起作用
    using A::func;
    func();
    func(10);
    func(10,20);
}
#endif
//using 编译指令使整个命名空间标识符可用
namespace A {
    int a =125;
}
namespace B {
    int a = 14;
}
void test7(){
    using namespace A;//使用 A 的整个命名空间
    cout << "a:" << a << endl;
    //不会产生二义性
    int a = 13;
    cout << "a:" << a << endl;//就近原则选择局部变量
}
//不同命名空间中的同名成员使用的时候必须注意二义性
void tset8(){
    using namespace A;
    using namespace B;
    //二义性产生，不知道调用 A 还是 B 的 a
//     cout << "a:" << a << endl;  //err 要解决前边必须加作用域
}

int main(int argc, char *argv[])
{
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
    test7();
    return 0;
}
//总结：1、命名空间的定义(不能在 函数内 定义命名空间)
//           2、使用命名空间的成名 最安全的方式 命名空间名::成员名；
//           3、 using namespace 命名空间名; 是用整个命名空间；(using namespace A;)
//           4、单独 使用命名空间中的成员：using 命名空间名::成员名;( using  veryLongName2::a)
