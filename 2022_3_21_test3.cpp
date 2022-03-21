#include <iostream>
//名字控制- 命名空间(namespace)
using namespace std;
//定义命名空间A
namespace A
{
    int a = 15;
    namespace C//嵌套
    {
        int a=18;
    }
}
namespace B
{
    int a =51;
}

namespace B
{
    //将c加入已有的命名空间中
    int c =100;
   //函数
    int Add(int x,int y)
    {
        return x+y;
    }
    void Print();//函数声明
}
void  B::Print()//成员函数
{
    //访问本命名空间的数据不用加作用域
    cout<<a<<endl;
}
void  Print1()//普通函数
{
    //外部定义时访问命名空间时必须加作用域
    cout<<B::a<<endl;
}

int main(int argc, char *argv[])
{
    cout << "A "<< A::a << endl;
    cout << "B " << B::a<<endl;
    cout << "C " << A::C::a<<endl;//嵌套
    cout << "c " << B::c<<endl;
    int ret = B::Add(5,6);
    cout << "ret = "<<ret<<endl;
    Print1();
    B::Print();
    return 0;
}
