#include <iostream>
#include <string.h>
using namespace std;
#if 0

class Person
{
private:
    char m_name[32];//定义类的时候不要给成员初始化
    int m_age;
public:
    //初始化函数
    void initPerson(char* name, int age)
    {
        if(name != NULL)
            strcpy(m_name,name);
        else
            cout<<"请初始化姓名"<<endl;
        if(age > 0 && age < 100)
            m_age = age;
        else
            cout<<"请重新初始化年龄"<<endl;
    }
    //对成员 m_name 进行写操作
    void setName(char* name)
    {
        if(name != NULL)
            strcpy(m_name,name);
        else
            cout<<"请初始化姓名"<<endl;
    }
    //对成员 m_name 进行读操作
    char* getName(void)
    {
        return m_name;
    }
    //对成员 m_age 进行写操作
    void setAge(int age)
    {
        if(age > 0 && age < 100)
        {
         m_age = age;
        }
        else
        {
            cout<<"赋值无效"<<endl;
        }
    }
    //对成员 m_age 进行读操作
    int getAge(void)
    {
        return m_age;
    }
    void showPerson(void)
    {
        cout<<"姓名:"<<m_name<<" 年龄:"<<m_age<<endl;
    }

};
void test()
{
    //通过类 实例化 一个对象 （用Person定义一个变量）
    Person lucy;
    lucy.initPerson("老王",28);
    lucy.showPerson();
    lucy.setName("lucy");
    lucy.setAge(13);
    cout<<"姓名："<<lucy.getName()<<endl;
    cout<<"年龄："<<lucy.getAge()<<endl;

}

//设计一个长方体的类
class Cube
{
private:
    int m_L;
    int m_W;
    int m_H;
public://设计功能要单一
    //m_L m_W m_H 写操作
    void set_L(int l)
     {
       m_L = l;
     }
    void set_W(int w)
     {
       m_W = w;
     }
    void set_H(int h)
     {
       m_H = h;
     }
     //m_L m_W m_H 读操作
    int get_L(void)const
    {
        return m_L;
    }
    int get_W(void)const
    {
        return m_W;
    }
    int get_H(void)const
    {
        return m_H;
    }
    //计算面积
    int get_S(void)const
    {
        return 2*(m_L * m_W + m_L * m_H + m_W * m_H);
    }

    //计算体积
    int get_V(void)const
    {
        return m_L * m_W * m_H;
    }
    //成员函数判断
    bool myCompareCube2(Cube &ob)//类的内部 没有权限之分
    {
        if(m_L == ob.m_L && m_W == ob.m_W && m_H == ob.m_H)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }

};
bool myCompareCube1(const Cube &c1, const Cube &c2)
{
    //类的外部
    if(c1.get_L() == c2.get_L() && c1.get_W() == c2.get_W() && c1.get_H() == c2.get_H())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test()
{
    Cube cube1;
    cube1.set_L(10);
    cube1.set_W(10);
    cube1.set_H(10);
    /*int V = cube.get_V();
    cout << "体积："<< V << endl;*/
    cout << "体积:"<< cube1.get_V() << endl;
    cout << "面积:"<< cube1.get_S() << endl;

    Cube cube2;
    cube2.set_L(10);
    cube2.set_W(20);
    cube2.set_H(10);

    //全局函数判断
    if(myCompareCube1(cube1, cube2) == true)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    Cube cube3;
    cube3.set_L(10);
    cube3.set_W(10);
    cube3.set_H(10);
    //成员函数判断
    if(cube3.myCompareCube2(cube1) == true)
    {
        cout<<"相同"<<endl;
    }
    else
    {
        cout<<"不同"<<endl;
    }
}
#endif
//设计一个圆形类和一个点类 - 点和圆的关系
//点的类
class Point
{
private:
    int m_x;
    int m_y;
public:
    void setX(int x=0)
    {
        m_x = x;
    }
    void setY(int y=0)
    {
        m_y = y;
    }
    int getX(void)
    {
        return m_x;
    }
    int getY(void)
    {
        return m_y;
    }
};
//圆的类
class Circle
{
private:
    Point m_p;//圆心
    int m_r;
public:
    void steR(int r)
    {
        m_r = r;
    }
    int getR(void)
    {
        return m_r;
    }
    void setP(int x, int y)
    {
        m_p.setX(x);
        m_p.setY(y);
    }
    Point getP(void)
    {
        return m_p;//得到圆心
    }
    //判断 点在圆的位置
    void isPointOnCircle(Point &ob)
    {
        //点到圆心的距离
        int distance = (m_p.getX() - ob.getX()) * (m_p.getX() - ob.getX()) + (m_p.getY() - ob.getY()) * (m_p.getY() - ob.getY());
        if(distance < m_r * m_r)
        {
            cout<<"点在圆内"<<endl;
        }
        else if(distance == m_r * m_r)
        {
            cout<<"点在圆上"<<endl;
        }
        else
        {
            cout<<"点在圆外"<<endl;
        }
    }
};
void test()
{
    //实例化一个点对象
    Point point;
    point.setX(10);
    point.setY(10);

    //实例化一个圆对象
    Circle circle;
    circle.steR(30);//半径
    circle.setP(40,40);//圆心

    //判断 点 与 圆 的关系
    circle.isPointOnCircle(point);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
