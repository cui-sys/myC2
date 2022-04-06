#include <iostream>

using namespace std;
//【类和对象】
#if 0
//C 语言的思想：数据和方法是分开的
//数据
typedef struct
{
    char name [32];
    int age;
}Person;//人
typedef struct
{
    char name[32];
    int age;
    int type;
}Animal;//动物
//方法
void PersonEat(Person* p)
{
    cout<<p->name<<"正在吃饭"<<endl;
}
void AnimalEat(Animal* p)
{
    cout<<p->name<<"正在吃狗粮"<<endl;
}
void test()
{
    Person person = { "老王", 43 };
    Animal dog = { "狗子", 3 };

    PersonEat(&person);
    AnimalEat(&dog);

    //数据和方法独立容易造成方法调用错误数据
    AnimalEat((Animal*)&person);
}
#endif
//【封装】- 把变量（属性）和函数（操作）合成一个整体，封装在一个类中
//对变量和函数进行访问控制（公有）（私有）（保护）
//在类的内部（作用域范围内），没有访问权限之分，所有成员可以相互访问
//在类的外部（作用域范围外），访问权限才有意义：public(公有), private(私有), protected(保护)
//在类的外部,只有 public 修饰的成员才能被访问，在没有涉及继承与派生时，private 和 protected 是同等级的，外部不允许访问。
//【类的初识】 -
/*
            class 类名 {//抽象的概念 系统不会为其分配空间
                private://私有 类的外部不可直接访问
                protected://保护
                数据
                public://公有 类的外部可以直接访问
                方法


                //在类的内部没有权限之分 可以相互访问
            };
*/
class  Person{
private:
    int m_money;//私有数据
protected:
    int m_age;//保护数据
public://公有数据
    void dese()
    {
        m_money = 100;//在类的内部没有权限之分 可以相互访问
        m_age = 23;
        cout<<"嘚瑟!"<< " 年龄" << m_age<< " 钱数" << m_money <<endl;
    }
};

void test()
{
    //用类 去 实例化 一个对象(就是用 Person 定义一个变量)
    Person lucy;
    //lucy.m_money = 200;// err 私有数据 类的外部不可访问
    //cout <<"年龄多少"<<lucy.m_age<<endl;// err 保护数据 类的外部不可访问

    lucy.dese();// ok 公有数据 可以访问
    // pricate, protected 虽然有访问权限 类外不可访问，但是可以借助 public 公有的方法 间接的访问 私有、保护 的数据。
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
