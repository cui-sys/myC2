#include <iostream>
//���ֿ���- �����ռ�(namespace)
using namespace std;
//���������ռ�A
namespace A
{
    int a = 15;
    namespace C//Ƕ��
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
    //��c�������е������ռ���
    int c =100;
   //����
    int Add(int x,int y)
    {
        return x+y;
    }
    void Print();//��������
}
void  B::Print()//��Ա����
{
    //���ʱ������ռ�����ݲ��ü�������
    cout<<a<<endl;
}
void  Print1()//��ͨ����
{
    //�ⲿ����ʱ���������ռ�ʱ�����������
    cout<<B::a<<endl;
}

int main(int argc, char *argv[])
{
    cout << "A "<< A::a << endl;
    cout << "B " << B::a<<endl;
    cout << "C " << A::C::a<<endl;//Ƕ��
    cout << "c " << B::c<<endl;
    int ret = B::Add(5,6);
    cout << "ret = "<<ret<<endl;
    Print1();
    B::Print();
    return 0;
}
