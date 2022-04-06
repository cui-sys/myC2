#include <iostream>
#include <string.h>
using namespace std;
#if 0

class Person
{
private:
    char m_name[32];//�������ʱ��Ҫ����Ա��ʼ��
    int m_age;
public:
    //��ʼ������
    void initPerson(char* name, int age)
    {
        if(name != NULL)
            strcpy(m_name,name);
        else
            cout<<"���ʼ������"<<endl;
        if(age > 0 && age < 100)
            m_age = age;
        else
            cout<<"�����³�ʼ������"<<endl;
    }
    //�Գ�Ա m_name ����д����
    void setName(char* name)
    {
        if(name != NULL)
            strcpy(m_name,name);
        else
            cout<<"���ʼ������"<<endl;
    }
    //�Գ�Ա m_name ���ж�����
    char* getName(void)
    {
        return m_name;
    }
    //�Գ�Ա m_age ����д����
    void setAge(int age)
    {
        if(age > 0 && age < 100)
        {
         m_age = age;
        }
        else
        {
            cout<<"��ֵ��Ч"<<endl;
        }
    }
    //�Գ�Ա m_age ���ж�����
    int getAge(void)
    {
        return m_age;
    }
    void showPerson(void)
    {
        cout<<"����:"<<m_name<<" ����:"<<m_age<<endl;
    }

};
void test()
{
    //ͨ���� ʵ���� һ������ ����Person����һ��������
    Person lucy;
    lucy.initPerson("����",28);
    lucy.showPerson();
    lucy.setName("lucy");
    lucy.setAge(13);
    cout<<"������"<<lucy.getName()<<endl;
    cout<<"���䣺"<<lucy.getAge()<<endl;

}

//���һ�����������
class Cube
{
private:
    int m_L;
    int m_W;
    int m_H;
public://��ƹ���Ҫ��һ
    //m_L m_W m_H д����
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
     //m_L m_W m_H ������
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
    //�������
    int get_S(void)const
    {
        return 2*(m_L * m_W + m_L * m_H + m_W * m_H);
    }

    //�������
    int get_V(void)const
    {
        return m_L * m_W * m_H;
    }
    //��Ա�����ж�
    bool myCompareCube2(Cube &ob)//����ڲ� û��Ȩ��֮��
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
    //����ⲿ
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
    cout << "�����"<< V << endl;*/
    cout << "���:"<< cube1.get_V() << endl;
    cout << "���:"<< cube1.get_S() << endl;

    Cube cube2;
    cube2.set_L(10);
    cube2.set_W(20);
    cube2.set_H(10);

    //ȫ�ֺ����ж�
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
    //��Ա�����ж�
    if(cube3.myCompareCube2(cube1) == true)
    {
        cout<<"��ͬ"<<endl;
    }
    else
    {
        cout<<"��ͬ"<<endl;
    }
}
#endif
//���һ��Բ�����һ������ - ���Բ�Ĺ�ϵ
//�����
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
//Բ����
class Circle
{
private:
    Point m_p;//Բ��
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
        return m_p;//�õ�Բ��
    }
    //�ж� ����Բ��λ��
    void isPointOnCircle(Point &ob)
    {
        //�㵽Բ�ĵľ���
        int distance = (m_p.getX() - ob.getX()) * (m_p.getX() - ob.getX()) + (m_p.getY() - ob.getY()) * (m_p.getY() - ob.getY());
        if(distance < m_r * m_r)
        {
            cout<<"����Բ��"<<endl;
        }
        else if(distance == m_r * m_r)
        {
            cout<<"����Բ��"<<endl;
        }
        else
        {
            cout<<"����Բ��"<<endl;
        }
    }
};
void test()
{
    //ʵ����һ�������
    Point point;
    point.setX(10);
    point.setY(10);

    //ʵ����һ��Բ����
    Circle circle;
    circle.steR(30);//�뾶
    circle.setP(40,40);//Բ��

    //�ж� �� �� Բ �Ĺ�ϵ
    circle.isPointOnCircle(point);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
