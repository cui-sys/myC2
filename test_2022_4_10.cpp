#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;
#if 0
//【深拷贝、浅拷贝】
//【浅拷贝】:同一类型的对象之间可以赋值，是的两个对象的成员变量的值相同，两个对象仍然是独立的两个对象，这种情况被称为浅拷贝。
//一般情况下，浅拷贝没有任何副作用，但是当类中有指针，并且指针指向动态分配的内存空间，析构函数做了动态内存释放的处理，会导致内存问题
class Person
{
private:
    char *m_name;
    int m_num;
public:
    Person()
    {
        m_name = NULL;
        m_num = 0;
        cout<<"无参构造"<<endl;
    }
    Person(char* name,int num)
    {
        //为m_name从堆区申请空间
        m_name = (char*)calloc(1,strlen(name)+1);
        if(m_name == NULL)
        {
            cout<<"构造失败"<<endl;
        }
        cout<<"已申请好空间"<<endl;
        strcpy(m_name,name);
        m_num = num;
        cout<<"有参构造"<<endl;
    }
    void showPerson(void)
    {
        cout<<"m_name:"<<m_name<<", m_num = "<<m_num<<endl;
    }
    Person(const Person &ob)
    {
        cout<<"拷贝构造函数"<<endl;
        m_name = (char*)(1,strlen(ob.m_name)+1);
        cout<<"已申请好空间"<<endl;
        strcpy(m_name,ob.m_name);
        m_num = ob.m_num;
    }

    ~Person()
    {
        if(m_name != NULL)
        {
            free(m_name);
            m_name = NULL;
        }
        cout<<"析构函数"<<endl;
        cout<<"空间已被释放"<<endl;
    }
};
void test()
{
    Person lucy("lucy",200);
    lucy.showPerson();

    //浅拷贝的lucy问题 （多次释放同一块堆区空间）
    //通过自定义 拷贝函数 完成深拷贝动作
    Person bob = lucy;//调用系统的默认拷贝构造（浅拷贝）
    bob.showPerson();
}

//【多个对象构造和析构】
//构造函数和其他函数不同，除了有名字，参数列表，函数体之外还有初始化列表。
// 初始化列表：


class Data
{private:
    int m_a;
    int m_b;
    int m_c;
public:
    Data(int a,int b,int c):m_a(a),m_b(b),m_c(c)//初始化列表 - 成员名（形参名）
    {
        //m_a = a;
        //m_b = b;
        //m_c = c;
        cout<<"有参构造"<<endl;
    }
    //【注意】：初始化列表（参数列表）只能在构造函数使用。
    //但一个类中没有指针成员的时候，析构函数内容可以不用做
    ~Data()
    {
         cout<<"析构函数"<<endl;
    }
    void showData(void)
    {
        cout<<"a="<<m_a<<", b="<<m_b<<", c="<<m_c<<endl;
    }
};
void test()
{
    Data data(10,20,30);
    data.showData();
}

//【类的对象作为另一个类的成员】
//在类的定义的数据成员一般都是基本的数据类型。但是类中的成员也可以是对象，叫做对象成员。
class A
{
private:
    int m_a;
public:
    A()
    {
        cout<<"A无参构造"<<endl;
    }
    A(int a)
    {
        cout<<"A有参构造"<<endl;
    }
    ~A()
    {
        cout<<"A析构函数"<<endl;
    }
};
class B
{
private:
    int m_b;
public:
    B()
    {
        cout<<"B无参构造"<<endl;
    }
    B(int b)
    {
        cout<<"B有参构造"<<endl;
    }
    ~B()
    {
        cout<<"B析构函数"<<endl;
    }
};
class Data
{
private:
    A obA;//对象成员
    B obB;
    int data;//基本类型成员
public:
    Data()
    {
        cout<<"Data无参构造"<<endl;
    }
    //初始化列表 显示调用 调用对象成员的构造函数
    Data(int a,int b,int c):obA(a),obB(b),data(c)//必须在Data的构造函数中 使用初始化列表 使其对象成员调用有参构造
    {
        //obA.m_a = a;//err
        //obB.m_b = b;//在对象成员类中是私有的
        //data = c;
        cout<<"Data有参构造"<<endl;
    }

    ~Data()
    {
        cout<<"Data析构函数"<<endl;
    }
};
void test()
{
    //系统会调用 Data 的无参构造 （之前 保证 子对象的构造函数先调用）
    //Data ob1;//先调用对象成员的构造函数，再调用自己的构造函数---->先析构自己，再析构对象成员

    // 系统默认调用对象成员的无参构造
    Data ob2(10,20,30);

}

//【关键字 explicit】 - 禁止通过构造函数进行隐式转换。
// 声明为 explicit 的构造函数不能在隐式转换中使用
//explicit 用于修饰构造函数，放置隐式转换。是针对单参数的构造函数（或者除了第一个参数外其他参数都是默认值的多参数构造）而言。
class Data
{
private:
    int m_a;
public:
    // explicit 该有参构造函数 不允许 隐式转换
    explicit Data(int a):m_a(a)
    {

        cout<<"Data有参构造"<<endl;
    }
    void showData(void)
    {
        cout<<"m_a:"<<m_a<<endl;
    }

    ~Data()
    {
        cout<<"Data析构函数"<<endl;
    }
};
void test()
{
    //隐式转换
    // Data ob1 = 10;//Data ob1(10) err-(容易被看成赋值)//explicit 该有参构造函数 不允许 隐式转换
    Data ob1(10);//ok
    ob1.showData();

    Data ob2 = Data(23);//ok - 显示调用有参构造
    ob2.showData();
}
#endif
//【动态对象的创建】

void test()
{

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
