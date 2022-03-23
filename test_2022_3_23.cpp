#include <iostream>

using namespace std;
#if 0
//���������ռ䣬ֻ���ڱ��ļ�ʹ�ã��൱�ڸ������ʶ�������� static ,ʹ���������Ϊ�ڲ�����
//namespace {
//    int a=10;
//}
//�����������ռ��ֱ�ӷ��ʣ����������ռ価������
//void test1(){
//    cout<<"a:"<<a<<endl;
//}

//�����ռ����
namespace veryLongName {
     int a = 10;
     void func(){
         cout<<"hello namespace"<<endl;
     }
}
void test2(){
   namespace shorName = veryLongName;
   shorName::func();
   veryLongName::func();
}

//using ���� - using ��������ʹ��ָ���ı�ʶ������ - ���˶������ռ�ķ��� - һ�㲻��ʹ�� - ����ȫ
//���׳�ͻ��1�������������ռ��Ա������ͻ      2����ֲ�������ͻ
namespace veryLongName2{
    int a=100;
    void fund(){
        cout<<"hello namespace2"<<endl;
    }
}
void test3(){
    int b = 1000;
    int a = 200;
    //�ӵ�ǰλ��ʹ�� veryLongName2 �����ռ䣻
    using namespace veryLongName2;
    //�·����ֵı����ȴ� veryLongName2 ���ռ����ң��Ҳ����ٴ�����·���ң��Ҳ������ᱨ��
     cout<<"a="<<a<<endl;//���ʾֲ����� - ���ᱨ��
     cout<<"a:"<< veryLongName2::a<<endl;//�ȫ
    fund();
}

//using ָ������������ռ� ��Ա
 int a = 15;//�ֲ��������ó�ȫ�ֱ�������ʹ�� - ���ֵ������ռ�һ��Ҳ����ʹ�� - ����ȫ
void test4(){

    using  veryLongName2::a;//�������׺������ֲ�������ͻ���ᱨ��
    cout<<"a="<<a<<endl;
    cout<<"ȫ�ֱ��� a="<<::a<<endl;//ȫ�ֱ���Ĭ����(::)���η���
    //����fundʹ�õ�ʱ�򣬱���������� - ָ���ĸ�ֻ��ʹ���ĸ�,������Ա����Ҫ�����������ʹ��
    veryLongName2::fund();
}

//�������� - һ��������������������
//C������ ������ �����Ǻ�������ڵ�ַ
//C++ �� ������+���� ��ϴ����ƺ��������
namespace A {
    void func(){ cout << "�޲�" <<endl; }
    void func(int a){ cout << "1������" <<endl; }
    void func(int a,int b){cout << "��������" <<endl; }
}

void test5(){
    //usingָ�� ʹ�� A �е� func  ��� A �����е� func ������
//    using A::func;
//    func();
//    func(10);
//    func(10,20);
    A::func();
    A::func(10);
    A:: func(10,20);
}
void test6(){
    //usingָ�� ʹ�� A �е� func  ��� A �����е� func ������
    using A::func;
    func();
    func(10);
    func(10,20);
}
#endif
//using ����ָ��ʹ���������ռ��ʶ������
namespace A {
    int a =125;
}
namespace B {
    int a = 14;
}
void test7(){
    using namespace A;//ʹ�� A �����������ռ�
    cout << "a:" << a << endl;
    //�������������
    int a = 13;
    cout << "a:" << a << endl;//�ͽ�ԭ��ѡ��ֲ�����
}
//��ͬ�����ռ��е�ͬ����Աʹ�õ�ʱ�����ע�������
void tset8(){
    using namespace A;
    using namespace B;
    //�����Բ�������֪������ A ���� B �� a
//     cout << "a:" << a << endl;  //err Ҫ���ǰ�߱����������
}

int main(int argc, char *argv[])
{
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
    test7();
    return 0;
}
//�ܽ᣺1�������ռ�Ķ���(������ ������ ���������ռ�)
//           2��ʹ�������ռ�ĳ��� �ȫ�ķ�ʽ �����ռ���::��Ա����
//           3�� using namespace �����ռ���; �������������ռ䣻(using namespace A;)
//           4������ ʹ�������ռ��еĳ�Ա��using �����ռ���::��Ա��;( using  veryLongName2::a)
