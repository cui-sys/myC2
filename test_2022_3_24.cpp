#include <iostream>
//ʹ�ñ�׼�������ռ�
// std �е����г�Ա��������ֱ��ʹ��
//cout endl cin ���������ռ� std �ĳ�Ա
//using namespace std;
using namespace std;
#if 0
//C++ ���﷨����ǿ
// c ���Դ��룺
// int a = 10;//��ֵ����������
// int a;//ͬ����û�и�ֵ���������������û����һ��ͬ�����壬���д��뽫��ɶ��塣��
// c �����п��Խ������βζ���������ͣ���ʱ�βο������κ����ͣ��� C++ �б��������Ͷ���
// void fun1(i)
// {
//      printf("i = %d\n",i);
// }
// void fun2(i)
// {
//      printf("i = %s\n",i);
// }
// int main(){
//      printf("a:%d\n",a);
//      fun1(123);
//      fun2("string");
//      return EXIT_SUCCESS;
// }
//�˴����� C++ �±���ʧ�ܣ��� C �±���ͨ����
//�� C++ ��ͬ���͵ı���һ���ǲ���ֱ�Ӹ��Ƶģ���Ҫ��ӳ��ǿת��C �ǿ��Ե�
// typedef enum COLR{ GREEN, RED, YELLOW } color;
// int main()
// {
//      color mycolor = GREEN;
//      mycolor = 10;
//      printf("mycolor:%d\n", mycolor);
//      char* p = macolor(10);
//      return EXIT_SUCCESS;
// }
//���� C ���� C�����������ͨ����C++ �������޷�����ͨ����
//
//C++�Խṹ�����ǿ
// c �ж���ṹ�����Ҫ���� struct �ؼ��֣�c++ ����Ҫ��
// c �еĽṹ��ֻ�ܶ����Ա���������ܶ����Ա������
// c++ �ȿ��Զ����Ա������Ҳ���Զ����Ա������
// struct stu
// {
//     int num;
//     char name[32];
//     void func();//ree - c ���Բ������ڽṹ���ж����Ա����
// };
// void test1()
// {
//      //c ���Ա���ӹؼ��� struct
//      struct stu lucy = { 100��"lucy" };
// }
#endif
struct stu
 {
    int num;
    char name[32];
    void func();// c++ �����ڽṹ���ж����Ա����
 };
void test1()
{
    //c++ ���Բ��ü� struct
    stu lucy = { 100, "lucy" };
    //���ó�Ա����
    lucy.func();
}

enum COLR{ GREEN, RED, YELLOW };
int main(int argc, char *argv[])
{
//    std::cout << "hello world" << std::endl;
//    cout << "hello world" << endl;
    COLR mycolor = GREEN;
//    mycolor = 10;//ree
    test1();
    return 0;
}
