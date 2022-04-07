#include <iostream>

using namespace std;
//【构造函数的分类及调用】
//【分类】
//按参数类型：分为无参构造和有参构造
//按类型分类：普通构造函数和拷贝构造函数（赋值构造函数）

#if 0

class Data
{
public:
    int num;
public:
    //构造函数(无参的构造)
    Data()
    {
        num = 0;
        cout<<"无参的构造函数"<<num<<endl;
    }
    //构造函数(有参的构造)
    Data(int n)
    {
        num = n;
        cout<<"有参的构造函数"<<num<<endl;
    }
    //【拷贝构造函数】
    //拷贝构造函数 - 对象和对象之间的一个初始化动作
    Data(const Data &ob)//const Data &ob == ob1
    {
        //拷贝构造函数 是 ob2 调用 num 就是 ob2 的 num
        num = ob.num;
        cout<<"拷贝构造函数"<<endl;
    }

    //析构函数
    ~Data()
    {
         cout<<"析构函数"<<num<<endl;
    }

};
//【调用】
//无参构造的调用形式：
/*void test()
{
    //调用无参 或 默认 构造(隐式调用构造函数)
    Data ob;
    //Data ob();//不会实例化 不会认为是实例化对象ob 而是看成函数 ob() 的声明
    //调用无参构造(显示调用)
    Data ob1 = Data();

    //调用有参构造(隐式调用构造函数)
    Data ob2(20);
    //调用有参构造(显示调用)
    Data ob3 = Data(10);

    //隐式转换的方式 调用有参构造（针对于 只有一个数据成员）
    Data ob4 = 30;//等价于 Data ob4(30)

    //匿名对象(当前语句结束，匿名对象立即释放)
    Data(40);
    cout<<"--------"<<endl;

Data ob5(500);}*/
/*void test1()
{
    //只有旧对象初始化新对象 才调用 拷贝构造函数
    Data ob1(10);
    cout<<"ob1.num:"<<ob1.num<<endl;
    //拷贝构造函数的调用形式：
    // 如果用户不实现拷贝构造，系统将调用默认的拷贝构造（单纯地整体赋值 - 浅拷贝）
    // 如果用户实现了拷贝构造 系统将调用用户实现的拷贝构造默认的会被屏蔽
    Data ob2 = ob1;// == Data ob2(ob1)(隐式调用拷贝构造函数)
    cout<<"ob2.num:"<<ob2.num<<endl;
    Data ob3 = Data(ob2);//(显示调用拷贝构造函数)
    cout<<"ob3.num:"<<ob3.num<<endl;

}*/
void test2()
{
    Data ob1(10);//调用有参构造
    Data ob2;//调用无参构造

    ob2 = ob1;//对象的赋值

    cout<<"ob1.num:"<<ob1.num<<endl;
    cout<<"ob2.num:"<<ob2.num<<endl;
}

//【注意】：在同一作用域 构造和析构的顺序相反
//         不能调用拷贝构造函数去初始化匿名对象
#endif
//【构造函数的调用规则】
// 系统会对任何一个类提供三个成员函数：
//1、默认构造函数(空) 2、默认析构函数(空) 3、默认拷贝构造函数(浅拷贝)
// 如果用户提供了有参构造 将屏蔽 系统的默认构造函数
// 如果用户提供了有参构造 不会屏蔽 系统的默认拷贝构造函数
// 如果用户提供了拷贝构造函数 将屏蔽 系统的默认构造函数、默认拷贝构造函数
class Data
{
public:
    int num;
public:
    //构造函数(有参的构造)
    Data(int n)
    {
        num = n;
        cout<<"有参的构造函数"<<num<<endl;
    }
    Data(const Data &ob)//const Data &ob == ob1
    {
        //拷贝构造函数 是 ob2 调用 num 就是 ob2 的 num
        num = ob.num;
        cout<<"拷贝构造函数"<<endl;
    }
    //析构函数
    ~Data()
    {
         cout<<"析构函数"<<num<<endl;
    }

};
void test()
{
    //Data ob1;//err 如果用户提供了有参构造 将屏蔽 系统的默认构造函数
    Data ob1(10);
    Data ob2(ob1);//如果用户提供了有参构造 不会屏蔽 系统的默认拷贝构造函数
    cout<<"ob2.num:"<<ob2.num<<endl;
}

int main(int argc, char *argv[])
{
    test();
    //test1();
    //test2();
    return 0;
}
//【总结】：对于构造函数：用户一般要实现 无参构造 有参构造 拷贝构造 析构

