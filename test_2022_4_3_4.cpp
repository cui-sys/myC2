#include <iostream>

using namespace std;
//����������Ϊ�˼̳к꺯����Ч�ʣ�û�к�������ʱ�Ŀ�����Ȼ���ֿ�������ͨ�������������Խ��в���������ֵ���͵İ�ȫ��飬�ֿ�����Ϊ��Ա����
//����������һ�������ĺ���
#if 0
inline int my_Add(int x, int y)
{
    return x+y;
}
//���ж���ĳ�Ա���������Զ�������������
//ע�⣺��������
//1.�������κ���ʽ��ѭ�����
//2.���ܴ��ڹ���������ж����
//3.�����岻�ܹ����Ӵ� ���ܶԺ�������ȡ��ַ����

void test()
{
    cout<<"my_Add:"<<my_Add(5+6,8+7)<<endl;
}

//�����ġ�Ĭ�ϲ�����- ȱʡ����
inline int my_Add(int x=10, int y=20)
{
    return x+y;
}
void test()
{
    //����������� ��ô����Ĭ�ϲ�������Ч
    cout<<"my_Add:"<<my_Add(100,200)<<endl;//300

    //���ĳ������Υ������ ������Ĭ��ֵ x=100 y ʹ��Ĭ��ֵ20
    cout<<"my_Add:"<<my_Add(100)<<endl;//120

    //�����ν�����Ĭ��ֵ x=10 y=20
    cout<<"my_Add:"<<my_Add()<<endl;//30
}

//������Ĭ�ϲ����������ң����һ������������Ĭ�ϲ�������ô�������֮��Ĳ�������������Ĭ�ϲ���
int func(int x,int y=10,int z=20)
{
    return x+y+z;
}

void test()
{
    cout << "�����" <<func(100,200)<<endl ;
    cout << "�����" <<func(100)<<endl ;
    // cout << "�����" <<func()<<endl ;//err - xû������Ĭ�ϲ��� ���봫��
}

//������������˺�������ֿ�д�����������ͺ������岻��ͬʱ����Ĭ�ϲ���
//���ļ� �������崦��Ĭ�ϲ�������Ч��
//���� �����ڶ����ʱ��Ҫ����Ĭ�ϲ��� ����������ʱ����
extern int func(int x,int y=15,int z=25);
//extern int func(int x,int y,int z);err
void test()
{
    cout << "�����" <<func(100,200)<<endl ;
    cout << "�����" <<func(100)<<endl ;
}

//������ռλ���� - C++ ����������ʱ����������ռλ����ֻ�в���������������û�в�����������
//һ������£��ں������ڲ��޷�ʹ��չλ������
//ռλ����û���β������ǵ����õ�ʱ����봫��
void func1 (int x,int y,int)
{
    cout<<"x+y:"<<x+y<<endl;
}

void test()
{
    func1(20,30,40);
}

//���������ء�(voerload) - ʹ���ַ���ʹ��
//ͬһ�������ڲ�ͬ�ĳ����в�ͬ�ĺ���
//ʵ�ֺ������ص�������ͬһ������ ������ͬ �������Ͳ�ͬ ����˳��ͬ


namespace A
{
    void myFunc(void){cout<<"�޲�"<<endl;}
    void myFunc(int a){cout<<"1��int����"<<endl;}
    void myFunc(int a,int b){cout<<"����int����"<<endl;}
    void myFunc(double a){cout<<"1��double����"<<endl;}
    void myFunc(int a,double b){cout<<"1��int����_1��double����"<<endl;}
    //int myFunc(int a,double b){cout<<"1��int����_1��double����"<<endl;}//err - ���������Բ�������
}
void test()
{
    A::myFunc();
    A::myFunc(20);
    A::myFunc(20,30);
    A::myFunc(2.5);
    A::myFunc(12,2.3);
}
//��������ֵ���Ͳ�����Ϊ�������ص�����
#endif
int main(int argc, char *argv[])
{
   test();
    return 0;
}
