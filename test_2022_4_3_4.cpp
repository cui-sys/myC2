#include <iostream>

using namespace std;
//内联函数：为了继承宏函数的效率，没有函数调用时的开销，然后又可以像普通函数那样，可以进行参数，返回值类型的安全检查，又可以作为成员函数
//内联函数是一个真正的函数
#if 0
inline int my_Add(int x, int y)
{
    return x+y;
}
//类中定义的成员函数都会自动生成内联函数
//注意：内联函数
//1.不能有任何形式的循环语句
//2.不能存在过多的条件判断语句
//3.函数体不能过于庞大 不能对函数进行取地址操作

void test()
{
    cout<<"my_Add:"<<my_Add(5+6,8+7)<<endl;
}

//函数的【默认参数】- 缺省参数
inline int my_Add(int x=10, int y=20)
{
    return x+y;
}
void test()
{
    //如果函数传参 那么各自默认参数将无效
    cout<<"my_Add:"<<my_Add(100,200)<<endl;//300

    //如果某够参数违背传参 将启用默认值 x=100 y 使用默认值20
    cout<<"my_Add:"<<my_Add(100)<<endl;//120

    //不传参将启用默认值 x=10 y=20
    cout<<"my_Add:"<<my_Add()<<endl;//30
}

//函数的默认参数从左往右，如果一个参数设置了默认参数，那么这个参数之后的参数都必须设置默认参数
int func(int x,int y=10,int z=20)
{
    return x+y+z;
}

void test()
{
    cout << "结果：" <<func(100,200)<<endl ;
    cout << "结果：" <<func(100)<<endl ;
    // cout << "结果：" <<func()<<endl ;//err - x没有设置默认参数 必须传参
}

//如果函数声明核函数定义分开写，函数声明和函数定义不能同时设置默认参数
//分文件 函数定义处的默认参数是无效的
//建议 函数在定义的时候不要设置默认参数 可以在声明时设置
extern int func(int x,int y=15,int z=25);
//extern int func(int x,int y,int z);err
void test()
{
    cout << "结果：" <<func(100,200)<<endl ;
    cout << "结果：" <<func(100)<<endl ;
}

//函数的占位参数 - C++ 在声明函数时，可以设置占位参数只有参数类型声明，而没有参数名声明。
//一般情况下，在函数体内部无法使用展位参数。
//占位参数没有形参名但是调用用的时候必须传参
void func1 (int x,int y,int)
{
    cout<<"x+y:"<<x+y<<endl;
}

void test()
{
    func1(20,30,40);
}

//【函数重载】(voerload) - 使名字方便使用
//同一个函数在不同的场景有不同的含义
//实现函数重载的条件：同一作用域 参数不同 参数类型不同 参数顺序不同


namespace A
{
    void myFunc(void){cout<<"无参"<<endl;}
    void myFunc(int a){cout<<"1个int参数"<<endl;}
    void myFunc(int a,int b){cout<<"两个int参数"<<endl;}
    void myFunc(double a){cout<<"1个double参数"<<endl;}
    void myFunc(int a,double b){cout<<"1个int参数_1个double参数"<<endl;}
    //int myFunc(int a,double b){cout<<"1个int参数_1个double参数"<<endl;}//err - 产生二义性不能重载
}
void test()
{
    A::myFunc();
    A::myFunc(20);
    A::myFunc(20,30);
    A::myFunc(2.5);
    A::myFunc(12,2.3);
}
//函数返回值类型不能作为函数重载的依据
#endif
int main(int argc, char *argv[])
{
   test();
    return 0;
}
