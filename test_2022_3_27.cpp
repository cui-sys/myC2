// const �ܽ�
#include <iostream>
//�� C ������ const ����ȫ�ֱ��� num ������ֻ�� �ڴ�ռ������ֳ�����(ֻ��)������ͨ�� num �ĵ�ַ �޸Ŀռ�����
// const ���ξֲ����� ������ֻ�� �ڴ�ռ���ջ��(�ɶ���д)����ͨ����ַ ����޸Ŀռ�����
using namespace std;
#if 0

//
//extern const int date;// const ���ε�ȫ�ֱ��� Ĭ�����ڲ����ӣ�ֻ�ڵ�ǰԴ�ļ���Ч������ֱ����������Դ�ļ���
//extern const int date = 5000;//����ʱ���¶���
extern const int date;
void test()
{
    cout << "ȫ��date = " << date <<endl;
}

//���� const �滻 #define
//#define ������ ���ɽ������ͼ��
// const �������򣬶� #define ������������Ĭ�϶��崦���ļ���β��������õ�����������Ч�ĳ�������ô#define �Ͳ�����
#define MAX 1024//Ԥ����׶α���Ļ�ֱ�ӱ� 1024 ������MAX
const short my_max = 1024 ; //const �����ͣ��ɽ��б��������Ͱ�ȫ���
void func(short i)
{
    cout<<"short ����"<<endl;
}
void func(int i)
{
    cout<<"int ����"<<endl;
}
void test()
{
    func(MAX);//int
    func(my_max);//short
}

void func(void)
{
    //���÷�Χ �ǵ�ǰ�������
    const int num = 10;

    //���÷�Χ ��ǰλ�õ��ļ�����
    #define NUM 10
}
void test()
{
//    cout<<"num = "<<num<<endl;//-err ��ʶ��
    cout<<"NUM = "<<NUM<<endl;
}

// �곣�������������ռ䣬���� const �ǿ����е�
namespace myspace
{
    #define MY_A 100
    //MY_A ���������ļ� �����ڸ������ռ�
    const int my_a = 100;
}
void test()
{
    cout <<"myspace:my_a = "<<myspace::my_a<<endl;
    //cout <<"myspace:MY_A = "<<myspace::MY_A<<endl;//-err
    cout <<"MY_A = "<<MY_A<<endl;
}
#endif
//����(reference)
void test()
{

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
