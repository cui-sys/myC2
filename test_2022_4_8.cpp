#include <iostream>

using namespace std;
//�����캯���ķ��༰���á�
//�����ࡿ
//���������ͣ���Ϊ�޲ι�����вι���
//�����ͷ��ࣺ��ͨ���캯���Ϳ������캯������ֵ���캯����

#if 0
#endif
class Data
{
public:
    int num;
public:
    //���캯��(�޲εĹ���)
    Data()
    {
        num = 0;
        cout<<"�޲εĹ��캯��"<<num<<endl;
    }
    //���캯��(�вεĹ���)
    Data(int n)
    {
        num = n;
        cout<<"�вεĹ��캯��"<<num<<endl;
    }
    //���������캯����
    //�������캯�� - ����Ͷ���֮���һ����ʼ������
    Data(const Data &ob)//const Data &ob == ob1
    {
        //�������캯�� �� ob2 ���� num ���� ob2 �� num
        num = ob.num;
        cout<<"�������캯��"<<endl;
    }

    //��������
    ~Data()
    {
         cout<<"��������"<<num<<endl;
    }

};
//�����á�
//�޲ι���ĵ�����ʽ��
/*void test()
{
    //�����޲� �� Ĭ�� ����(��ʽ���ù��캯��)
    Data ob;
    //�����޲ι���(��ʾ����)
    Data ob1 = Data();

    //�����вι���(��ʽ���ù��캯��)
    Data ob2(20);
    //�����вι���(��ʾ����)
    Data ob3 = Data(10);

    //��ʽת���ķ�ʽ �����вι��죨����� ֻ��һ�����ݳ�Ա��
    Data ob4 = 30;//�ȼ��� Data ob4(30)

    //��������(��ǰ���������������������ͷ�)
    Data(40);
    cout<<"--------"<<endl;

Data ob5(500);}*/
/*void test1()
{
    //ֻ�оɶ����ʼ���¶��� �ŵ��� �������캯��
    Data ob1(10);
    cout<<"ob1.num:"<<ob1.num<<endl;
    //�������캯���ĵ�����ʽ��
    // ����û���ʵ�ֿ������죬ϵͳ������Ĭ�ϵĿ������죨���������帳ֵ - ǳ������
    Data ob2 = ob1;// == Data ob2(ob1)(��ʽ���ÿ������캯��)
    cout<<"ob2.num:"<<ob2.num<<endl;
    Data ob3 = Data(ob2);//(��ʾ���ÿ������캯��)
    cout<<"ob3.num:"<<ob3.num<<endl;

}*/
void test2()
{
    Data ob1(10);//�����вι���
    Data ob2;//�����޲ι���

    ob2 = ob1;//����ĸ�ֵ

    cout<<"ob1.num:"<<ob1.num<<endl;
    cout<<"ob2.num:"<<ob2.num<<endl;
}

//��ע�⡿����ͬһ������ �����������˳���෴
int main(int argc, char *argv[])
{
    //test();
    //test1();
    test2();
    return 0;
}
