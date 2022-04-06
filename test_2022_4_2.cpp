#include <iostream>

using namespace std;
#if 0

//函数重载和默认参数一起使用，需要注意二义性问题的产生。
void myFunc(int a)
{
    cout<<"一个int参数"<<endl;
}
/*
void myFunc(int a, int b=10)//默认参数
{
    cout<<"两个int参数"<<endl;
}
*/
void test()
{
    myFunc(10);
}
#endif
//
//
void test()
{

}

int main()
{
    test();
    return 0;
}
//函数的默认参数从左到右，如果一个参数设置了默认参数，那么这个参数之后的参数都必须设置默认参数。
