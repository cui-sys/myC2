#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;
#if 0
//�������ǳ������
//��ǳ������:ͬһ���͵Ķ���֮����Ը�ֵ���ǵ���������ĳ�Ա������ֵ��ͬ������������Ȼ�Ƕ������������������������Ϊǳ������
//һ������£�ǳ����û���κθ����ã����ǵ�������ָ�룬����ָ��ָ��̬������ڴ�ռ䣬�����������˶�̬�ڴ��ͷŵĴ����ᵼ���ڴ�����
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
        cout<<"�޲ι���"<<endl;
    }
    Person(char* name,int num)
    {
        //Ϊm_name�Ӷ�������ռ�
        m_name = (char*)calloc(1,strlen(name)+1);
        if(m_name == NULL)
        {
            cout<<"����ʧ��"<<endl;
        }
        cout<<"������ÿռ�"<<endl;
        strcpy(m_name,name);
        m_num = num;
        cout<<"�вι���"<<endl;
    }
    void showPerson(void)
    {
        cout<<"m_name:"<<m_name<<", m_num = "<<m_num<<endl;
    }
    Person(const Person &ob)
    {
        cout<<"�������캯��"<<endl;
        m_name = (char*)(1,strlen(ob.m_name)+1);
        cout<<"������ÿռ�"<<endl;
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
        cout<<"��������"<<endl;
        cout<<"�ռ��ѱ��ͷ�"<<endl;
    }
};
void test()
{
    Person lucy("lucy",200);
    lucy.showPerson();

    //ǳ������lucy���� ������ͷ�ͬһ������ռ䣩
    //ͨ���Զ��� �������� ����������
    Person bob = lucy;//����ϵͳ��Ĭ�Ͽ������죨ǳ������
    bob.showPerson();
}

//������������������
//���캯��������������ͬ�����������֣������б�������֮�⻹�г�ʼ���б�
// ��ʼ���б�


class Data
{private:
    int m_a;
    int m_b;
    int m_c;
public:
    Data(int a,int b,int c):m_a(a),m_b(b),m_c(c)//��ʼ���б� - ��Ա�����β�����
    {
        //m_a = a;
        //m_b = b;
        //m_c = c;
        cout<<"�вι���"<<endl;
    }
    //��ע�⡿����ʼ���б������б�ֻ���ڹ��캯��ʹ�á�
    //��һ������û��ָ���Ա��ʱ�������������ݿ��Բ�����
    ~Data()
    {
         cout<<"��������"<<endl;
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

//����Ķ�����Ϊ��һ����ĳ�Ա��
//����Ķ�������ݳ�Աһ�㶼�ǻ������������͡��������еĳ�ԱҲ�����Ƕ��󣬽��������Ա��
class A
{
private:
    int m_a;
public:
    A()
    {
        cout<<"A�޲ι���"<<endl;
    }
    A(int a)
    {
        cout<<"A�вι���"<<endl;
    }
    ~A()
    {
        cout<<"A��������"<<endl;
    }
};
class B
{
private:
    int m_b;
public:
    B()
    {
        cout<<"B�޲ι���"<<endl;
    }
    B(int b)
    {
        cout<<"B�вι���"<<endl;
    }
    ~B()
    {
        cout<<"B��������"<<endl;
    }
};
class Data
{
private:
    A obA;//�����Ա
    B obB;
    int data;//�������ͳ�Ա
public:
    Data()
    {
        cout<<"Data�޲ι���"<<endl;
    }
    //��ʼ���б� ��ʾ���� ���ö����Ա�Ĺ��캯��
    Data(int a,int b,int c):obA(a),obB(b),data(c)//������Data�Ĺ��캯���� ʹ�ó�ʼ���б� ʹ������Ա�����вι���
    {
        //obA.m_a = a;//err
        //obB.m_b = b;//�ڶ����Ա������˽�е�
        //data = c;
        cout<<"Data�вι���"<<endl;
    }

    ~Data()
    {
        cout<<"Data��������"<<endl;
    }
};
void test()
{
    //ϵͳ����� Data ���޲ι��� ��֮ǰ ��֤ �Ӷ���Ĺ��캯���ȵ��ã�
    //Data ob1;//�ȵ��ö����Ա�Ĺ��캯�����ٵ����Լ��Ĺ��캯��---->�������Լ��������������Ա

    // ϵͳĬ�ϵ��ö����Ա���޲ι���
    Data ob2(10,20,30);

}

//���ؼ��� explicit�� - ��ֹͨ�����캯��������ʽת����
// ����Ϊ explicit �Ĺ��캯����������ʽת����ʹ��
//explicit �������ι��캯����������ʽת��������Ե������Ĺ��캯�������߳��˵�һ��������������������Ĭ��ֵ�Ķ�������죩���ԡ�
class Data
{
private:
    int m_a;
public:
    // explicit ���вι��캯�� ������ ��ʽת��
    explicit Data(int a):m_a(a)
    {

        cout<<"Data�вι���"<<endl;
    }
    void showData(void)
    {
        cout<<"m_a:"<<m_a<<endl;
    }

    ~Data()
    {
        cout<<"Data��������"<<endl;
    }
};
void test()
{
    //��ʽת��
    // Data ob1 = 10;//Data ob1(10) err-(���ױ����ɸ�ֵ)//explicit ���вι��캯�� ������ ��ʽת��
    Data ob1(10);//ok
    ob1.showData();

    Data ob2 = Data(23);//ok - ��ʾ�����вι���
    ob2.showData();
}
#endif
//����̬����Ĵ�����

void test()
{

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
